bits 64


global memmove:function


section .text

memmove:
    xor rcx, rcx
begin:
    cmp rdx, rcx
    je stop
    mov r9b, [rsi + rcx]
    mov [rdi + rcx], r9b
    inc rcx
    jmp begin
stop:
    mov rax, rdi
    ret
