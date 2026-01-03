#ifndef __K_UTILS_H
#define __K_UTILS_H

#include "types.h"

void print (const char *s, u8 colour);

void clear_vga_buffer ();

void clear_vga_buffer_range (const int start, const int end);

/* Macros */
#define VGA_BUFFER_SIZE 2000
#define CLEAR_CHAR 127

#endif /* __K_UTILS_H */
