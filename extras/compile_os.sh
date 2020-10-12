#!/bin/bash

rm -f bootSector.bin

nasm -f bin bootSector.asm -o bootSector.bin

# To compile and execute
# sh compile_os.sh
# qemu-system-x86_64 bootSector.bin