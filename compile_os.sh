#!/bin/bash

rm -f *.o
rm -f isabellaos.bin
rm -f isodir/boot/isabellaos.bin
rm -f isabellaos.iso

nasm -felf32 asm/boot.asm -o boot.o

i686-elf-gcc -c kernel/kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I./include
i686-elf-gcc -c libc/vga/vga.c -o vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I./include

i686-elf-gcc -T linker.ld -o isabellaos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o vga.o -lgcc

cp isabellaos.bin isodir/boot/isabellaos.bin

grub-mkrescue -o isabellaos.iso isodir

# To compile and execute
# sh compile_os.sh
# qemu-system-i386 -cdrom isabellaos.iso
# qemu-system-i386 -kernel isabellaos.bin # without grub