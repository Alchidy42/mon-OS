#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

// Déclarations des fonctions principales
void kernel_main();
void handle_interrupt(uint8_t interrupt_number);
void* allocate_memory(size_t size);
void schedule_next_process();

#endif // KERNEL_H
