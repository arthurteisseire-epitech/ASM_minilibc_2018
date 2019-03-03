bits 64


global strstr:function


section .text

strstr:
    mov rax, rdi
    xor rcx, rcx
    mov r10b, [rsi]
    cmp r10b, 0
    je found

loop:
    mov rax, rdi
    add rax, rcx

    mov r9b, [rax]
    cmp r9b, [rsi]
    je found
    cmp r9b, 0
    je not_found
    inc rcx
    jmp loop

not_found:
    mov rax, 0

found:
    ret
