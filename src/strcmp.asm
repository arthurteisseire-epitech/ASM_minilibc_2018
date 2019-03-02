bits 64


global strcmp:function


section .text

strcmp:
    xor eax, eax
    mov r9b, [rsi]
    cmp [rdi], r9b
    jl negative
    mov al, [rdi]
    sub al, [rsi]
    ret
negative:
    mov al, [rsi]
    sub al, [rdi]
    xor eax, 0xffffffff
    inc eax
    ret
