# MyOS - Un système d'exploitation minimaliste

**MyOS** est un système d'exploitation rudimentaire conçu pour des fins éducatives. Il est basé sur un noyau simple et un shell textuel pour permettre l'interaction avec l'utilisateur. Il n'inclut pas d'interface graphique, mais permet d'exécuter des commandes de base dans un environnement textuel.

## Fonctionnalités actuelles

- **Noyau minimaliste** : Un noyau simple avec gestion de la mémoire et des interruptions.
- **Shell textuel** : Une interface utilisateur en ligne de commande permettant d'exécuter des commandes comme `echo`, `help`, et d'autres commandes personnalisées.
- **Drivers basiques** : Support pour des périphériques comme le clavier et l'écran VGA.
- **Multi-tasking** : Le noyau prend en charge le multitâche basique.
  
## Structure du projet

Le projet est organisé de la manière suivante :


/monOS
│
├── /bootloader        # Code source et fichiers liés au bootloader
│   ├── boot.asm       # Code assembleur pour initialiser le système
│   └── bootloader.c   # Code pour charger le noyau
│
├── /kernel            # Noyau principal
│   ├── main.c         # Point d'entrée du noyau
│   ├── interrupts.c   # Gestion des interruptions
│   ├── memory.c       # Gestion de la mémoire
│   ├── scheduler.c    # Gestion des processus (multitâche)
│   └── kernel.h       # Fichier d'en-tête principal du noyau
│
├── /drivers           # Drivers pour gérer le matériel
│   ├── keyboard.c     # Driver clavier
│   ├── vga.c          # Driver pour l'écran (texte/graphique)
│   ├── disk.c         # Driver disque
│   └── drivers.h      # Fichier d'en-tête pour les drivers
│
├── /lib               # Bibliothèques système
│   ├── stdio.c        # Fonctions d'entrée/sortie standard
│   ├── string.c       # Fonctions de manipulation de chaînes
│   └── lib.h          # Fichier d'en-tête des bibliothèques
│
├── /shell             # Interface utilisateur
│   ├── shell.c        # Programme principal du shell
│   └── shell.h        # Fichier d'en-tête du shell
│
├── /docs              # Documentation du projet
│   └── README.md      # Instructions et description
│
└── /build             # Fichiers générés (binaires, ISO, etc.)
    ├── monOS.bin      # Fichier binaire final de l'OS
    └── monOS.iso      # Fichier ISO bootable



## Compilation

Pour compiler le système d'exploitation, suivez les étapes ci-dessous.

1. **Prérequis** :
   - Un environnement de développement comme [GCC](https://gcc.gnu.org/) ou [Clang](https://clang.llvm.org/).
   - [QEMU](https://www.qemu.org/) pour émuler l'OS.
   - Un éditeur de texte pour modifier les fichiers source.

2. **Étapes de compilation** :
   - Clonez ce dépôt sur votre machine.
   - Dans le répertoire du projet, exécutez les commandes suivantes :

     ```bash
     make clean  # Nettoie les fichiers de compilation précédents
     make        # Compile le noyau et le bootloader
     ```

3. **Exécution dans QEMU** :
   - Une fois la compilation terminée, vous pouvez démarrer l'OS dans QEMU avec la commande suivante :

     ```bash
     make run
     ```

   Cette commande lance QEMU avec l'image du système d'exploitation compilé.

## Commandes du Shell

Le shell prend en charge les commandes suivantes :

- **`help`** : Affiche la liste des commandes disponibles.
- **`echo <message>`** : Affiche un message à l'écran.

Exemple d'utilisation :

