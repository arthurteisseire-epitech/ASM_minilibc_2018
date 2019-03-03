bits 64


global rindex:function


section .text

rindex:
    xor rcx, rcx
    xor rax, rax
    xor r8, r8
begin:
    mov r8, rdi
    add r8, rcx
    mov r9b, [r8]
    cmp r9b, sil
    cmove rax, r8
    cmp r9b, 0
    je return
    inc rcx
    jmp begin

return:
    ret
