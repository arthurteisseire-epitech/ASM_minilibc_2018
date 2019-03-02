bits 64


global strcmp:function


section .text

strcmp:
    mov r9b, [rsi]
    cmp [rdi], r9b
    je equal
    jmp not_equal
equal:
    mov rax, 0
    ret
not_equal:
    xor r10, r10
    mov r10b, [rdi]
    sub r10b, [rsi]
    movzx rax, r10b
    ret
