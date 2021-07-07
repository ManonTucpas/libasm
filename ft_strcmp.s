;rsi && cl = s1 || rdi && dl= s2 || 
;rax = 0 of s1 = s2
;rax < 0 if s1 < s2
;rax > 0 of s1 > s2

bits 64

section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax		;initialise rax to 0
	ft_loop:
		mov cl, [rdi + rax]	;move rdi[rax] to cl
		mov dl, [rsi + rax]	;move rsi[rax] to dl
		cmp cl, dl			;compare if cl = dl
		jne difference		;jump to difference if not equal
		cmp cl, 0			;compare cl to see if it is == '/0'
		je  same_string		;if cmp == '/0' jump to same_string
		inc rax				;rax++
		jmp	ft_loop			;do the loop from the begining for the next char

	difference:
        movzx   rcx, byte [rdi + rax]	;cpy just the char and fill the rest of rcx
        movzx   rdx, byte [rsi + rax]	;cpy just the char and fill the rest of rdx
		mov		rax, rcx
		sub     rax, rdx				;rdx - rax to have the result of the string comparison
        ret
		
	same_string:
		mov rax, 0		;the strings are the same then the return is == 0
		ret