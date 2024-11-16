#ifndef DRIVERS_H
#define DRIVERS_H

#include <stdint.h>

// Déclarations pour le clavier
void keyboard_initialize();
char keyboard_read_char();

// Déclarations pour l'écran
void vga_initialize();
void vga_clear_screen();
void vga_put_char(char c, uint8_t color);
void vga_put_string(const char* str, uint8_t color);

// Déclarations pour le disque
void disk_initialize();
int disk_read_sector(uint32_t lba, uint8_t* buffer);
int disk_write_sector(uint32_t lba, const uint8_t* buffer);

#endif // DRIVERS_H
