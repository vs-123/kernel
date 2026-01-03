#include <stdint.h>

void
kernel_main ()
{
   volatile uint16_t *vga_buffer = (uint16_t *)0xB8000;
   const char *str               = "Hello, vs-123!";
   uint8_t color                 = 0x0F;

   for (int i = 0; str[i] != '\0'; i++)
      {
         vga_buffer[i] = (uint16_t)color << 8 | str[i];
      }

   while (1)
      {
      }
}
