bits 64


global strncmp:function


section .text

strncmp:
    xor eax, eax
    xor rcx, rcx
    xor r9b, r9b
    xor r8b, r8b
    dec rdx
begin:
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    inc rcx

    cmp rdx, 0
    je return
    cmp r8b, 0
    je return
    cmp r9b, 0
    je return
    dec rdx
    cmp r8b, r9b
    je begin
return:
    cmp r8b, r9b
    jg positive

    mov al, r9b
    sub al, r8b
    xor eax, 0xffffffff
    inc eax
    ret
positive:
    mov al, r8b
    sub al, r9b
    ret
