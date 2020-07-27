#!/bin/bash

rm -f boot.o
rm -f kernel.o
rm -f isabellaos.bin
rm -f isodir/boot/isabellaos.bin
rm -f isabellaos.iso

i686-elf-as boot.s -o boot.o
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T linker.ld -o isabellaos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

cp isabellaos.bin isodir/boot/isabellaos.bin

grub-mkrescue -o isabellaos.iso isodir

# To compile and execute
# sh compile_os.sh
# qemu-system-i386 -cdrom isabellaos.iso