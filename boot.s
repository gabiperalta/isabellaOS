.set ALIGN,     1<<0 # mueve los bits a la izquierda la cantidad de veces indicada a la derecha
.set MEMINFO,   1<<1 # en este caso el numero resultante es 2
.set FLAGS,     ALIGN | MEMINFO # deberia ser 3
.set MAGIC,     0x1BADB002
.set CHECKSUM,  -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:

        mov $stack_top, %esp

        call kernel_main

        cli
1:      hlt
        jmp 1b

.size _start, . - _start