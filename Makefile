CC        = clang
LD        = ld.lld

CCOPTS    = -target i386-pc-none-elf -march=i386 -m32 -std=c99 -ffreestanding -O2 -Wall -Wextra
LDOPTS    = -m elf_i386 -T linker.ld
BUILD     = build/

.PHONY: b r c

b:
	@mkdir -p $(BUILD)
	@echo "COMPILING ASM..."
	nasm -f elf32 -o $(BUILD)boot.o boot.asm

	@echo "COMPILING C..."
	$(CC) $(CCOPTS) -o $(BUILD)kmain.o -c kmain.c

	@echo "LINKING..."
	$(LD) $(LDOPTS) -o $(BUILD)kernel.bin $(BUILD)boot.o $(BUILD)kmain.o

	@echo "BUILT SUCCESSFULLY!"

r: b
	@echo "RUNNING..."
	qemu-system-i386 -kernel $(BUILD)kernel.bin

c:
	@echo "CLEANING..."
	rm -rf $(BUILD)
