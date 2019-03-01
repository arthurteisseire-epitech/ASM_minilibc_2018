bits 64


global my_strlen:function


section .text

my_strlen:
    mov al, [rdi]
    cmp al, 0
    je setend
    mov al, 1
setend:
    ret
