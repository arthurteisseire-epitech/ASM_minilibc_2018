bits 64


global strpbrk:function


section .text


strpbrk:
    xor rcx, rcx

loop:
    mov rax, rdi
    add rax, rcx
    mov r9b, [rax]

    cmp r9b, 0
    je not_found
    jmp strcmp

inc_rcx:
    inc rcx
    jmp loop

strcmp:
    mov r11, 0

loopcmp:
    mov r10b, [rsi + r11]

    cmp r10b, 0
    je inc_rcx
    cmp r10b, r9b
    je found
    inc r11
    jmp loopcmp

not_found:
    xor rax, rax

found:
    ret
