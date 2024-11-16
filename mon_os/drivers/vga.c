#include "drivers.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_ADDRESS 0xB8000

static uint16_t* vga_buffer = (uint16_t*)VGA_ADDRESS;

// Couleurs
enum VGA_COLOR {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_WHITE = 15
};

// Initialisation du VGA
void vga_initialize() {
    vga_clear_screen();
}

// Efface l'écran
void vga_clear_screen() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = (VGA_COLOR_BLACK << 8) | ' ';
        }
    }
}

// Affiche un caractère à l'écran
void vga_put_char(char c, uint8_t color) {
    static uint16_t cursor_position = 0;
    if (c == '\n') {
        cursor_position += VGA_WIDTH - (cursor_position % VGA_WIDTH);
    } else {
        vga_buffer[cursor_position++] = (color << 8) | c;
    }
}

// Affiche une chaîne
void vga_put_string(const char* str, uint8_t color) {
    while (*str) {
        vga_put_char(*str++, color);
    }
}
