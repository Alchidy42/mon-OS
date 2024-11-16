#ifndef LIB_H
#define LIB_H

#include <stdint.h>

// Déclarations pour les fonctions de gestion des chaînes
void* memset(void* ptr, int value, size_t num);
char* strcpy(char* dest, const char* src);
int strcmp(const char* str1, const char* str2);
size_t strlen(const char* str);

// Déclarations pour les fonctions d'entrée/sortie
void print_char(char c);
void print_string(const char* str);

#endif // LIB_H
