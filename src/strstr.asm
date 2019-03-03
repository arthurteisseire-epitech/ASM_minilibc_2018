bits 64


global strstr:function


section .text

strstr:
    xor rcx, rcx
    mov r10b, [rsi]
    cmp r10b, 0
    je found

loop:
    mov r9b, [rdi + rcx]
    cmp r9b, [rsi]
    je found
    cmp r9b, 0
    je not_found
    inc rcx
    jmp loop

found:
    mov rax, rdi
    add rax, rcx
    ret

not_found:
    mov rax, 0
    ret
