bits 64


global my_strlen:function


section .text

my_strlen:
    mov al, [rdi]
    ret
