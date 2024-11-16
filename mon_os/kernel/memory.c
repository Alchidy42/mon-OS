#include "kernel.h"

// Simple gestion de la mémoire (exemple très basique)
static uint8_t memory_pool[1024 * 1024]; // 1 Mo de mémoire
static size_t memory_offset = 0;

void initialize_memory() {
    print("Initialisation de la mémoire...\n");
    memory_offset = 0;
}

// Alloue un bloc de mémoire
void* allocate_memory(size_t size) {
    if (memory_offset + size > sizeof(memory_pool)) {
        print("Erreur : mémoire insuffisante !\n");
        return NULL;
    }
    void* ptr = &memory_pool[memory_offset];
    memory_offset += size;
    return ptr;
}
