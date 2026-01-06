#include "vga.h"
#include "types.h"

volatile u16 *vga_buffer = (u16 *)0xB8000;
u32 vga_cursor = 0;

void
print_char (char c, u8 colour)
{
   switch (c)
      {
      case '\t':
         {
            vga_cursor += 4;
         }
         break;
      case '\n':
         {
            vga_cursor = ((vga_cursor / 80) + 1) * 80 - 1;
         }
         break;
      default:
         vga_buffer[vga_cursor] = (u16)colour << 8 | c;
         break;
      }
   vga_cursor++;
}

void
print (const char *s, u8 colour)
{
   for (int i = 0; s[i] != '\0'; i++)
      {
	 print_char(s[i], colour);
      }
}

void
clear_vga_buffer ()
{
   clear_vga_buffer_range (0, VGA_BUFFER_SIZE);
}

void
clear_vga_buffer_range (const int start, const int end)
{
   for (int i = start; i < end; i++)
      {
         vga_buffer[i] = CLEAR_CHAR;
      }
}
