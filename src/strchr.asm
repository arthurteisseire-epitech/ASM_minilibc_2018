bits 64


global strchr:function


section .text

strchr:
    xor rcx, rcx
begin:
    mov dl, [rdi + rcx]
    cmp dl, sil
    je return
    inc rcx
    jmp begin
return:
    mov rax, rdi
    add rax, rcx
    ret
