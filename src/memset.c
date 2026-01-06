#include "memset.h"

void *
memset (void *buf, int c, int size)
{
   unsigned char *tmp = (unsigned char *)buf;
   unsigned char val  = (unsigned char)c;

   unsigned int word = val | (val << 8) | (val << 16) | (val << 24);

   int i = 0;
   while (size >= 4)
      {
         *(unsigned int *)&tmp[i] = word;
         i += 4;
         size -= 4;
      }

   while (size > 0)
      {
         tmp[i] = val;
         i++;
         size--;
      }

   return buf;
}
