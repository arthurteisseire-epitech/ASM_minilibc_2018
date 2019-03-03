bits 64


global memmove:function


section .text

memmove:
    xor rcx, rcx
    xor r9, r9
    cmp rdi, rsi
    jl memcpy
    jmp move

memcpy:
    cmp rdx, rcx
    je stop
    mov r9b, [rsi + rcx]
    mov [rdi + rcx], r9b
    inc rcx
    jmp memcpy
stop:
    mov rax, rdi
    ret

move:
    cmp rdx, 0
    je return
    dec rdx
    mov r9b, [rsi + rdx]
    mov [rdi + rdx], r9b
    jmp move
return:
    mov rax, rdi
    ret
