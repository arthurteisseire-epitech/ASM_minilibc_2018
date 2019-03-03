bits 64


global strcspn:function


section .text


strcspn:
    xor rax, rax
    xor rdx, rdx

loop:
    mov rdx, rdi
    add rdx, rax
    mov r9b, [rdx]

    cmp r9b, 0
    je return
    jmp strcmp

inc_rcx:
    inc rax
    jmp loop

strcmp:
    mov r11, 0

loopcmp:
    mov r10b, [rsi + r11]

    cmp r10b, 0
    je inc_rcx
    cmp r10b, r9b
    je return
    inc r11
    jmp loopcmp

return:
    ret
