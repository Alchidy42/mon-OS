#include "kernel.h"

// Table des interruptions (simplifiée)
void initialize_interrupts() {
    print("Initialisation des interruptions...\n");
    // Ici, tu configures la table IDT (Interrupt Descriptor Table)
    // Exemple : IDT_SetGate(numéro, adresse_handler, type);
}

// Gestionnaire d'interruptions générique
void handle_interrupt(uint8_t interrupt_number) {
    print("Interruption reçue : ");
    print_int(interrupt_number);
    print("\n");
}
