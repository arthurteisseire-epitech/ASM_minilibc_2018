bits 64


global memset:function


section .text

memset:
    xor rcx, rcx
begin:
    cmp rdx, rcx
    je stop
    mov [rdi + rcx], sil
    inc rcx
    jmp begin
stop:
    mov rax, rdi
    ret
