#ifndef SHELL_H
#define SHELL_H

#include <stdint.h>

// Déclaration des fonctions pour le shell
void shell_main();                // Fonction principale du shell
void print_prompt();              // Affiche l'invite du shell
void execute_command(const char* command);  // Exécute une commande
void print_string(const char* str); // Affiche une chaîne de caractères
void shell_help();               // Affiche l'aide du shell

#endif // SHELL_H
