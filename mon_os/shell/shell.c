#include "shell.h"
#include "lib.h"  // Inclure la bibliothèque d'entrée/sortie

// Fonction principale du shell
void shell_main() {
    while (1) {
        print_prompt();  // Affiche l'invite
        char command[128];  // Tableau pour stocker la commande saisie
        int i = 0;

        // Lecture de l'entrée utilisateur caractère par caractère
        char c;
        while ((c = getchar()) != '\n' && i < sizeof(command) - 1) {
            command[i++] = c;
        }
        command[i] = '\0';  // Terminer la chaîne avec le caractère nul

        execute_command(command);  // Exécuter la commande saisie
    }
}

// Affiche l'invite de commande
void print_prompt() {
    print_string("MyOS> ");
}

// Exécute la commande saisie par l'utilisateur
void execute_command(const char* command) {
    if (strcmp(command, "help") == 0) {
        shell_help();
    }
    else if (strcmp(command, "echo") == 0) {
        print_string("Echo: ");
        char* param = (char*) (command + 5);  // Ignorer "echo " dans la commande
        print_string(param);  // Afficher ce qui suit "echo"
    }
    else {
        print_string("Command not found: ");
        print_string(command);
        print_string("\n");
    }
}

// Affiche l'aide du shell
void shell_help() {
    print_string("MyOS Shell - Available Commands:\n");
    print_string("help      - Displays this help message\n");
    print_string("echo <msg> - Echoes the input message\n");
    print_string("\n");
}
