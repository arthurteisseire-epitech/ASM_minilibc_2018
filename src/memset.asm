bits 64


global memset:function


section .text

memset:
    mov rax, rdi
    ret
