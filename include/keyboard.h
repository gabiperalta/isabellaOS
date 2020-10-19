#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include <irq.h>

void keyboard_handler(struct regs *r);
void keyboard_install();

#endif