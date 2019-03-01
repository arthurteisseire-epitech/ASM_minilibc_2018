bits 64


global my_strlen:function


section .text

my_strlen:
    xor rcx, rcx
begin:
    mov dl, [rdi + rcx]
    cmp dl, 0
    je return
    inc rcx
    jmp begin
return:
    mov rax, rcx
    ret
