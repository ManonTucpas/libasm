bits 64

section .text
    global ft_write
    extern __errno_location
    ft_write:
        mov rax, 1      ; 1 for write syscall
        syscall
        cmp rax, 0      ;cmp to 0 if less exit ft
        jl exit
        ret
    exit:
        neg rax         ;rax *= -1
        mov rdi, rax    ;put the rax , the return of write in rdi
        call __errno_location wrt ..plt
        mov [rax], rdi  ; [] -> address , we put rdi in the update of errno
        mov rax, -1         ;fail == -1 for write
        ret