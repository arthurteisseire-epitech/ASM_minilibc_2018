bits 64


global strlen:function


section .text

strlen:
    xor rcx, rcx
begin:
    mov r9b, [rdi + rcx]
    cmp r9b, 0
    je return
    inc rcx
    jmp begin
return:
    mov rax, rcx
    ret
