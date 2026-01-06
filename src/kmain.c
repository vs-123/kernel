#include "vga.h"
#include "types.h"
#include "io.h"

void
kmain ()
{
   clear_vga_buffer ();
   print ("Welcome to kernel!\n", 0x0F);
   print ("Enter name: ", 0x0F);

   char name[10];
   read_kbd (name);

   print ("Hi, ", 0x0F);
   print (name, 0x0F);
   print("!", 0x0F);
   

   while (1)
      {
      }
}
