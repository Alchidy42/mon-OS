#include <stdint.h>

// Simple fonction d'impression (nécessite des outils additionnels)
void print(const char* str) {
    while (*str) {
        asm volatile(
            "movb $0x0E, %%ah\n"
            "movb %0, %%al\n"
            "int $0x10"
            :
            : "r"(*str)
            : "%ah", "%al"
        );
        str++;
    }
}

// Fonction principale (appelle le noyau après initialisation)
void bootloader_main() {
    print("Passage au noyau...\n");

    // Charger le noyau ou effectuer des opérations avant le transfert
    // Exemple : appeler une fonction pour charger des données en mémoire

    // Passer le contrôle au noyau
    asm volatile("jmp 0x0000:0x8000");
}
