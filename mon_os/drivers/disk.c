#include "drivers.h"
#include <stddef.h>

#define DISK_PORT_DATA 0x1F0

void disk_initialize() {
    // Effectuer une initialisation spécifique si nécessaire
}

// Lecture d'un secteur disque
int disk_read_sector(uint32_t lba, uint8_t* buffer) {
    // Commande simplifiée pour ATA PIO
    outb(0x1F6, 0xE0 | ((lba >> 24) & 0x0F)); // LBA bits 24-27
    outb(0x1F2, 1);                           // Nombre de secteurs
    outb(0x1F3, lba & 0xFF);                  // LBA bits 0-7
    outb(0x1F4, (lba >> 8) & 0xFF);           // LBA bits 8-15
    outb(0x1F5, (lba >> 16) & 0xFF);          // LBA bits 16-23
    outb(0x1F7, 0x20);                        // Commande "Read Sectors"

    // Attente de la disponibilité
    while (!(inb(0x1F7) & 0x08));

    // Lecture des données
    for (int i = 0; i < 256; i++) {
        ((uint16_t*)buffer)[i] = inw(DISK_PORT_DATA);
    }
    return 0; // Succès
}

// Écriture d'un secteur disque
int disk_write_sector(uint32_t lba, const uint8_t* buffer) {
    // Implémentation similaire à `disk_read_sector`, mais pour l'écriture
    return 0; // Succès
}
