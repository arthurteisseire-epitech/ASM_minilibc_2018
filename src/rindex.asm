bits 64


global rindex:function


section .text

rindex:
    xor rcx, rcx
    xor rax, rax
begin:
    mov r9b, [rdi + rcx]
    cmp r9b, sil
    cmove rax, rdi
    cmp r9b, 0
    je return
    inc rcx
    jmp begin

return:
    ret
