
bits 64

section .text
    global  ft_strlen

ft_strlen:
    xor rax, rax
        again:
            mov cl, [rdi]   ;cl is the 8bit version , move rdi to cl
            cmp cl, 0       ;check is the char is '/0'
            je  exit        ;if the char is 0, jumpt to exit
            inc rax         ;increment the rax the counter
            inc rdi         ;increment rdi to go the next letter
            jmp again       ;jump again to the function again
        exit:
            ret             ;return automatically rax
