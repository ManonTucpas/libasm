;rdi = str

bits 64

section .text 
	global	ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy
 
ft_strdup:
	push rdi    	;put rdi - the string to copy - on the stack
	call ft_strlen	;count the lenght of rdi
	inc rax			;incremetn rax for the null char
	mov rdi, rax	;move strlen output to rdi for malloc
	call malloc wrt ..plt
	cmp rax, 0		;check if error
	je error		;if ==0 jump to error
	pop rdi			;take back the data rdi
	mov	rsi, rdi	;put rdi on rsi
	mov rdi, rax	;send output of malloc to rdi
	call ft_strcpy	;call for the copy
	ret
error:
	mov rax, 0
	ret