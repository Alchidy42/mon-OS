#include "drivers.h"
#include <stdint.h>
#include <stdbool.h>

// Port d'entrée du clavier PS/2
#define KEYBOARD_PS2_PORT_DATA 0x60
#define KEYBOARD_PS2_PORT_STATUS 0x64

// Tableau de correspondance (scancodes -> ASCII, simplifié)
static const char scancode_to_ascii[] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

// Variables pour le clavier USB (simplifiées pour cette démonstration)
static uint8_t usb_buffer[8];  // Buffer pour les données du clavier USB

// Détection du clavier PS/2 (simulation ici)
static bool ps2_keyboard_connected = true;  // Simuler la connexion d'un clavier PS/2

// Détection du clavier USB (simulation ici)
static bool usb_keyboard_connected = false; // Simuler l'absence de clavier USB (modifie selon le matériel réel)

// Fonction pour lire un octet à partir du port PS/2
static uint8_t read_ps2_data() {
    return inb(KEYBOARD_PS2_PORT_DATA);
}

// Initialisation du clavier PS/2
void keyboard_initialize_ps2() {
    // Initialisation du périphérique PS/2, par exemple l'activation des interruptions (si nécessaire)
    outb(KEYBOARD_PS2_PORT_STATUS, 0xAE);  // Exemple d'activation, à adapter selon le matériel
}

// Lecture d'un caractère depuis le clavier PS/2
char keyboard_read_char_ps2() {
    uint8_t scancode = read_ps2_data();  // Lire le scancode du clavier PS/2
    if (scancode < sizeof(scancode_to_ascii)) {
        return scancode_to_ascii[scancode];  // Conversion en caractère ASCII
    }
    return 0;
}

// Initialisation du clavier USB
void keyboard_initialize_usb() {
    // Initialisation spécifique pour un périphérique USB (interface HID)
    // Ici, la gestion des descripteurs HID et de la communication USB réelle serait nécessaire.
    // Pour l'instant, on se contente de la simulation.
    usb_keyboard_connected = true;
}

// Lecture des données du clavier USB (simulation basique)
void usb_read_data() {
    // Simulation d'une lecture de données depuis un clavier USB (doit être remplacée par de vraies interactions USB)
    usb_buffer[0] = 0x1E;  // Exemple de scancode (par exemple, 'A')
}

// Lecture d'un caractère depuis le clavier USB
char keyboard_read_char_usb() {
    usb_read_data();  // Lire les données du clavier USB
    uint8_t scancode = usb_buffer[0];  // Supposons que le premier octet contient le scancode
    if (scancode < sizeof(scancode_to_ascii)) {
        return scancode_to_ascii[scancode];  // Conversion en caractère ASCII
    }
    return 0;
}

// Fonction de lecture générique pour le clavier (PS/2 ou USB)
char keyboard_read_char() {
    if (ps2_keyboard_connected) {
        return keyboard_read_char_ps2();  // Lire un caractère depuis le clavier PS/2
    } else if (usb_keyboard_connected) {
        return keyboard_read_char_usb();  // Lire un caractère depuis le clavier USB
    }
    return 0;  // Aucun clavier détecté
}

// Fonction pour détecter si un clavier PS/2 est connecté
bool is_ps2_keyboard_connected() {
    // Logique pour détecter un périphérique PS/2 connecté (simulée ici)
    return ps2_keyboard_connected;
}

// Fonction pour détecter si un clavier USB est connecté
bool is_usb_keyboard_connected() {
    // Logique pour détecter un périphérique USB connecté (simulée ici)
    return usb_keyboard_connected;
}
