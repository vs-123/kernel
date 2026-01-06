#ifndef __K_VGA_H
#define __K_VGA_H

#include "types.h"

/* 80x25 = 2000 */
#define VGA_BUFFER_SIZE 2000
#define CLEAR_CHAR 0x0020

extern volatile u16 *vga_buffer;
extern u32 vga_cursor;

void print_char (char c, u8 colour);
void print (const char *s, u8 colour);
void clear_vga_buffer ();
void clear_vga_buffer_range (const int start, const int end);

#endif /* __K_VGA_H */
