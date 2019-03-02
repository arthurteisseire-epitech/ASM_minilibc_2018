bits 64


global strchr:function


section .text

strchr:
    xor rcx, rcx
begin:
    mov dl, [rdi + rcx]
    cmp dl, sil
    je found
    cmp dl, 0
    je not_found
    inc rcx
    jmp begin
found:
    mov rax, rdi
    add rax, rcx
    ret
not_found:
    mov rax, 0
    ret
