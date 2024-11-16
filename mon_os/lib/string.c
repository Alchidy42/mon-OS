#include "lib.h"

// Copie une chaîne de caractères src vers dest
char* strcpy(char* dest, const char* src) {
    char* original_dest = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Ajoute le caractère nul à la fin de la chaîne
    return original_dest;
}

// Compare deux chaînes de caractères
int strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

// Calcule la longueur d'une chaîne de caractères
size_t strlen(const char* str) {
    size_t len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

// Remplit un bloc mémoire avec une valeur donnée
void* memset(void* ptr, int value, size_t num) {
    unsigned char* p = ptr;
    while (num--) {
        *p++ = (unsigned char)value;
    }
    return ptr;
}
