bits 64


global memcpy:function


section .text

memcpy:
    cmp rdx, 0
    je return
    mov dl, [rsi]
    mov [rdi], dl
return:
    mov rax, rdi
    ret
