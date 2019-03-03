bits 64


global strstr:function


section .text

strstr:
    xor rcx, rcx
begin:
    mov r9b, [rdi + rcx]
    cmp r9b, [rsi]
    je found
    cmp r9b, 0
    je not_found
    inc rcx
    jmp begin
found:
    mov rax, rdi
    add rax, rcx
    ret
not_found:
    mov rax, 0
    ret
