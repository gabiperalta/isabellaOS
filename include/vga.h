#ifndef VGA_H
#define VGA_H
 
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

//static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);

//static inline uint16_t vga_entry(unsigned char uc, uint8_t color);
 
size_t strlen(const char* str);

 
void terminal_initialize(void);
 
void terminal_setcolor(uint8_t color);
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
 
void terminal_write(const char* data, size_t size);
 
void terminal_writestring(const char* data);

void terminal_scroll(void);
 
#endif