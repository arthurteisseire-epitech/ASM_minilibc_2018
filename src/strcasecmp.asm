bits 64


global strcasecmp:function


section .text

strcasecmp:
    xor eax, eax
    xor rcx, rcx
    xor rdx, rdx
begin:
    mov dh, [rdi + rcx]
    mov dl, [rsi + rcx]
    inc rcx

    cmp dh, 0
    je return
    cmp dl, 0
    je return
    cmp dh, dl
    je begin
return:
    cmp dh, dl
    jg positive

    mov al, dl
    sub al, dh
    xor eax, 0xffffffff
    inc eax
    ret
positive:
    mov al, dh
    sub al, dl
    ret
