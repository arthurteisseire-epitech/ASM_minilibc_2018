bits 64


global my_strlen:function


section .text

my_strlen:
    xor rcx, rcx
begin:
    mov dl, [rdi]
    cmp dl, 0
    je return
    inc rcx
    inc rdi
    mov rax, rcx
    jmp begin
return:
    ret
