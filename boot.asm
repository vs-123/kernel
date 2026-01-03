; MULTIBOOT STUFF
MB_MAGIC equ 0x1BADB002
MB_FLAGS equ 1 << 0 | 1 << 1
MB_CHKSM equ -(MB_MAGIC + MB_FLAGS)

section .multiboot
	dd MB_MAGIC
	dd MB_FLAGS
	dd MB_CHKSM

section .text
extern kernel_main
global _start

_start:
	mov esp, stack_top
	call kernel_main
	cli

.hang:
	hlt
	jmp .hang

section .bss
align 16
stack_bottom:
	resb 16384
stack_top:
