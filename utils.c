#include "utils.h"
#include "volatiles.h"

void
print (const char *s, u8 colour)
{
   for (int i = 0; s[i] != '\0'; i++)
      {
         vga_buffer[i] = (u16)colour << 8 | s[i];
      }
}
