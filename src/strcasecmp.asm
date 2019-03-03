bits 64


global strcasecmp:function


section .text

strcasecmp:
    xor eax, eax
    xor rcx, rcx
    xor r9b, r9b
    xor r8b, r8b
begin:
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    inc rcx

    cmp r8b, 90
    jle to_upper_r8
end_r8:
    cmp r9b, 90
    jle to_upper_r9
end_r9:

    cmp r8b, 0
    je return
    cmp r9b, 0
    je return
    cmp r8b, r9b
    je begin
return:
    cmp r8b, r9b
    jg positive

    mov al, r9b
    sub al, r8b
    xor eax, 0xffffffff
    inc eax
    ret
positive:
    mov al, r8b
    sub al, r9b
    ret

to_upper_r8:
    xor dl, dl
    mov dl, r8b
    add dl, 32
    cmp r8b, 65
    cmovge r8d, edx
    jmp end_r8

to_upper_r9:
    xor dl, dl
    mov dl, r9b
    add dl, 32
    cmp r9b, 65
    cmovge r9d, edx
    jmp end_r9
