#include "kernel.h"

// Structure pour un processus simple
typedef struct {
    uint32_t pid;
    void (*entry_point)();
    uint8_t active;
} Process;

// Tableau de processus (multitâche rudimentaire)
#define MAX_PROCESSES 4
static Process processes[MAX_PROCESSES];
static int current_process = 0;

void initialize_scheduler() {
    print("Initialisation du scheduler...\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i + 1;
        processes[i].entry_point = NULL;
        processes[i].active = 0;
    }
}

// Ajoute un processus au tableau
void create_process(void (*entry_point)()) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (!processes[i].active) {
            processes[i].entry_point = entry_point;
            processes[i].active = 1;
            print("Processus créé avec PID : ");
            print_int(processes[i].pid);
            print("\n");
            return;
        }
    }
    print("Erreur : nombre maximum de processus atteint.\n");
}

// Change de processus
void schedule_next_process() {
    current_process = (current_process + 1) % MAX_PROCESSES;
    if (processes[current_process].active && processes[current_process].entry_point) {
        processes[current_process].entry_point();
    }
}
