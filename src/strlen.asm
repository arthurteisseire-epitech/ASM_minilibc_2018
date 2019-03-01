bits 64


global my_strlen:function


section .text

my_strlen:
    push rbp
    mov rbp, rsp    ; Stack frame setup

    xor rcx, rcx
begin:
    mov dl, [rdi + rcx]
    cmp dl, 0
    je return
    inc rcx
    jmp begin
return:
    mov rax, rcx
    leave
    ret
