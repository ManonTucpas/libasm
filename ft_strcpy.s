;rdi = dest rsi = src || [rdi +rax] = dest[rax] || [rsi + rax] = src[rax]
;rax is a counter as scr[i] in c
bits 64

section .text 
	global	ft_strcpy

ft_strcpy:
	xor rax, rax			;put rax to 0
	again:
		mov cl, [rsi + rax]	;move src[0] in cl
		mov [rdi + rax], cl	;move cl which contains src[0] in dest[0]
		cmp cl, 0			;check if cl is null
		je	exit			;if = 0, jump tp exit 
		inc rax				;if not increment rax
		jmp	again			;jump to the begining until cl = null
	
	exit:
	mov [rdi + rax], cl		;mov cl in dest rdi for the '/0'
	mov rax, rdi			;move rdi = dest in rax which is the return value
	ret						;return rax