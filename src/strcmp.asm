bits 64


global strcmp:function


section .text

strcmp:
    mov r9b, [rsi]
    xor r10, r10
    mov r10b, [rdi]
    sub r10b, [rsi]
    movzx rax, r10b
    ret
