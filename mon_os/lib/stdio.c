#include "lib.h"

// Affiche un caractère à l'écran (assume que l'écran est en mode texte VGA)
void print_char(char c) {
    // Cette fonction devra envoyer le caractère au tampon vidéo VGA
    // Nous utilisons ici un affichage sur l'écran VGA par défaut
    extern void vga_put_char(char c, uint8_t color);
    vga_put_char(c, 0x0F); // Utilisation de la couleur blanche pour le texte
}

// Affiche une chaîne de caractères
void print_string(const char* str) {
    while (*str) {
        print_char(*str++);
    }
}
