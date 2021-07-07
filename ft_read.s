bits 64

section .text
    global ft_read
    extern __errno_location

ft_read:
   mov rax, 0       ;0 for read syscall
   syscall
   cmp rax, 0       ;cmp rax to 0 if <0 error
   jl error          ;if < 0 go to error function
   jmp no_error     ;go the exit(no-error) function

no_error:
    mov r9, 0
    push rax        ;save rax for later use
    call __errno_location wrt ..plt ;call to get pointer to error
    mov [rax],r9      ;put 0 into the location of error
    pop rax             ;restore original rax
    ret


error:
    neg rax         ;put rax positive
    mov rdi, rax    ;put the return of read in rdi
    call __errno_location wrt ..plt
    mov [rax], rdi  ;
    mov rax, -1
    ret