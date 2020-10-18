#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <vga.h>

#if defined(__linux__)
#error "No estas usando un cross-compiler"
#endif

#if !defined(__i386__)
#error "Esto necesita ser compilado con un compilador ix86-elf"
#endif

void kernel_main(void){
	/* Initialize terminal interface */
	terminal_initialize();
	//unsigned char numero = 5/0;
 
	/* Newline support is left as an exercise. */
	//terminal_writestring("Hello, kernel Mundo!\nhola");
	terminal_writestring("Hello, kernel Mundo!\n");
	//terminal_writestring("fervberbebrberberberberberbrbebreberberberberbebeberbrbebebebebrbrbrbrbrbrbrbrbra");
}