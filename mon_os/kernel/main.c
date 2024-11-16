#include "kernel.h"

// Fonction de démarrage du noyau
void kernel_main() {
    // Initialisation du système
    initialize_interrupts();
    initialize_memory();
    initialize_scheduler();

    // Message de bienvenue
    print("Bienvenue dans mon OS !\n");
    print("Tapez 'help' pour voir les commandes disponibles.\n");

    // Boucle principale (shell)
    char command[256];
    while (1) {
        print("> ");
        read_input(command, sizeof(command));
        if (strcmp(command, "help") == 0) {
            print("Commandes disponibles :\n");
            print(" - help : Afficher cette aide\n");
            print(" - shutdown : Éteindre le système\n");
        } else if (strcmp(command, "shutdown") == 0) {
            print("Arrêt du système...\n");
            break;
        } else {
            print("Commande inconnue.\n");
        }
    }

    // Arrêt du système
    shutdown_system();
}
