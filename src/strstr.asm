bits 64


global strstr:function


section .text


; '' , 'a'
; 0 , a

strstr:
    mov rax, rdi
    xor rcx, rcx
    mov r10b, [rsi]
    cmp r10b, 0
    je found

loop:
    mov rax, rdi
    add rax, rcx
    mov r8b, [rax]

    cmp r8b, 0
    je not_found
    cmp r8b, [rsi]
    je strcmp

inc_rcx:
    inc rcx
    jmp loop

strcmp:
    mov r11, 0

loopcmp:
    mov r9b, [rax + r11]
    mov r10b, [rsi + r11]

    cmp r10b, 0
    je found
    cmp r9b, 0
    je not_found
    cmp r10b, r9b
    jne inc_rcx
    inc r11
    jmp loopcmp

not_found:
    xor rax, rax

found:
    ret
