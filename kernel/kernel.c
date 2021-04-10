#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <vga.h>
#include <gdt.h>
#include <idt.h>
#include <isrs.h>
#include <irq.h>
#include <keyboard.h>
#include <multiboot.h>

#if defined(__linux__)
#error "No estas usando un cross-compiler"
#endif

#if !defined(__i386__)
#error "Esto necesita ser compilado con un compilador ix86-elf"
#endif

void kernel_main(multiboot_info_t* mbd,unsigned int magic){
	/* Initialize terminal interface */
	terminal_initialize();
	gdt_install();
	idt_install();
	isrs_install();
	irq_install();
	keyboard_install();

	__asm__ __volatile__ ("sti");

	//unsigned char numero = 5/0;
	//__asm__  ("div %0" :: "r"(0));
 
	/* Newline support is left as an exercise. */
	//terminal_writestring("Hello, kernel Mundo!\nhola");

	if(magic == MULTIBOOT_BOOTLOADER_MAGIC)
		terminal_writestring("es magic!\n");

	terminal_writestring("Hola, kernel Mundo!\n");
	
	//terminal_writestring("fervberbebrberberberberberbrbebreberberberberbebeberbrbebebebebrbrbrbrbrbrbrbrbra");

	for (;;);
}