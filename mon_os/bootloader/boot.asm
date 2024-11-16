BITS 16
ORG 0x7C00 

start:

    mov si, message
    call print_string


    mov ax, 0x0000
    mov es, ax
    mov bx, 0x8000
    mov ah, 0x02
    mov al, 0x10
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00
    mov dl, 0x80
    int 0x13
    jc load_error

    ; Passer au noyau
    jmp 0x0000:0x8000

load_error:
    mov si, error_message
    call print_string
    hlt


print_string:
    mov ah, 0x0E
.next_char:
    lodsb
    or al, al
    jz .done
    int 0x10
    jmp .next_char
.done:
    ret

message db "Bootloader en cours de chargement...", 0
error_message db "Erreur de chargement du noyau.", 0

times 510-($-$$) db 0
dw 0xAA55
