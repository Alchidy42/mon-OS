# Makefile pour compiler et générer un OS bootable

# Répertoires
BOOTLOADER_DIR = bootloader
KERNEL_DIR = kernel
DRIVERS_DIR = drivers
LIB_DIR = lib
SHELL_DIR = shell
BUILD_DIR = build

# Fichiers source et de sortie
BOOTLOADER_SRC = $(BOOTLOADER_DIR)/boot.asm $(BOOTLOADER_DIR)/bootloader.c
KERNEL_SRC = $(KERNEL_DIR)/main.c $(KERNEL_DIR)/interrupts.c $(KERNEL_DIR)/memory.c $(KERNEL_DIR)/scheduler.c
LIB_SRC = $(LIB_DIR)/stdio.c $(LIB_DIR)/string.c
SHELL_SRC = $(SHELL_DIR)/shell.c
OUTPUT_BIN = $(BUILD_DIR)/monOS.bin
OUTPUT_ISO = $(BUILD_DIR)/monOS.iso

# Compilateur
CC = gcc
ASM = nasm
LINKER = ld

# Options de compilation
CFLAGS = -m32 -ffreestanding -O2 -Wall
LDFLAGS = -m elf_i386 -Ttext 0x1000
ASMFLAGS = -f elf32

# Fichiers objets
BOOTLOADER_OBJ = $(BUILD_DIR)/boot.o $(BUILD_DIR)/bootloader.o
KERNEL_OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/interrupts.o $(BUILD_DIR)/memory.o $(BUILD_DIR)/scheduler.o
LIB_OBJ = $(BUILD_DIR)/stdio.o $(BUILD_DIR)/string.o
SHELL_OBJ = $(BUILD_DIR)/shell.o

# Dépendances
DEPS = $(BOOTLOADER_OBJ) $(KERNEL_OBJ) $(LIB_OBJ) $(SHELL_OBJ)

# Règles par défaut
all: $(OUTPUT_ISO)

# Générer l'ISO pour QEMU et VirtualBox
$(OUTPUT_ISO): $(OUTPUT_BIN)
	@echo "Génération de l'image ISO..."
	mkdir -p $(BUILD_DIR)/iso/boot/grub
	cp $(OUTPUT_BIN) $(BUILD_DIR)/iso/boot/monOS.bin
	echo "set timeout=0" > $(BUILD_DIR)/iso/boot/grub/grub.cfg
	echo "set default=0" >> $(BUILD_DIR)/iso/boot/grub/grub.cfg
	echo "menuentry 'MonOS' {" >> $(BUILD_DIR)/iso/boot/grub/grub.cfg
	echo "  multiboot /boot/monOS.bin" >> $(BUILD_DIR)/iso/boot/grub/grub.cfg
	echo "  boot" >> $(BUILD_DIR)/iso/boot/grub/grub.cfg
	echo "}" >> $(BUILD_DIR)/iso/boot/grub/grub.cfg
	grub-mkrescue -o $(OUTPUT_ISO) $(BUILD_DIR)/iso

# Compilation du bootloader
$(BUILD_DIR)/boot.o: $(BOOTLOADER_DIR)/boot.asm
	@echo "Compilation du bootloader..."
	$(ASM) $(ASMFLAGS) $< -o $@

$(BUILD_DIR)/bootloader.o: $(BOOTLOADER_DIR)/bootloader.c
	@echo "Compilation du bootloader C..."
	$(CC) -m32 -c $(BOOTLOADER_DIR)/bootloader.c -o $@

# Compilation du noyau
$(BUILD_DIR)/main.o: $(KERNEL_DIR)/main.c
	@echo "Compilation du noyau..."
	$(CC) $(CFLAGS) -c $(KERNEL_DIR)/main.c -o $@

$(BUILD_DIR)/interrupts.o: $(KERNEL_DIR)/interrupts.c
	@echo "Compilation des interruptions..."
	$(CC) $(CFLAGS) -c $(KERNEL_DIR)/interrupts.c -o $@

$(BUILD_DIR)/memory.o: $(KERNEL_DIR)/memory.c
	@echo "Compilation de la gestion de la mémoire..."
	$(CC) $(CFLAGS) -c $(KERNEL_DIR)/memory.c -o $@

$(BUILD_DIR)/scheduler.o: $(KERNEL_DIR)/scheduler.c
	@echo "Compilation du gestionnaire de processus..."
	$(CC) $(CFLAGS) -c $(KERNEL_DIR)/scheduler.c -o $@

# Compilation des bibliothèques
$(BUILD_DIR)/stdio.o: $(LIB_DIR)/stdio.c
	@echo "Compilation de la bibliothèque stdio..."
	$(CC) $(CFLAGS) -c $(LIB_DIR)/stdio.c -o $@

$(BUILD_DIR)/string.o: $(LIB_DIR)/string.c
	@echo "Compilation de la bibliothèque string..."
	$(CC) $(CFLAGS) -c $(LIB_DIR)/string.c -o $@

# Compilation du shell
$(BUILD_DIR)/shell.o: $(SHELL_DIR)/shell.c
	@echo "Compilation du shell..."
	$(CC) $(CFLAGS) -c $(SHELL_DIR)/shell.c -o $@

# Création de l'image binaire finale du noyau
$(OUTPUT_BIN): $(DEPS)
	@echo "Liaison du noyau..."
	$(LD) $(LDFLAGS) $(DEPS) -o $(OUTPUT_BIN)

# Nettoyage des fichiers générés
clean:
	@echo "Nettoyage des fichiers..."
	rm -rf $(BUILD_DIR)/*

# Lancer le système d'exploitation dans QEMU
run: $(OUTPUT_ISO)
	qemu-system-i386 -cdrom $(OUTPUT_ISO)

