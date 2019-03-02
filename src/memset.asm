bits 64


global memset:function


section .text

memset:
    cmp rdx, 0
    je stop
    mov [rdi], sil
stop:
    mov rax, rdi
    ret
