; lab 9 prelab 
; Liza trundle emt8kdn
; threexplusone.s


; optimization: i used shift (shr) to divide my number by 2 if even instead of using the idiv function, the shr bit shift operation is alot faster than dividing the registers \
; also xor rcx instead of moving 0 into it
; also changed imul rdi, 3 and then inc rdi into lea rdi, [rdi*3+1] to lower the number of steps 

global threexplusone

	section .text

; input = positive integer
; if integer is even, divide by 2
; if integer is odd, multiply by 3 and add 1 
; repeat until integer reaches 1 

;if (n==1)
;	return 0;	
;else if (n%2==0)
;	return 1+ collatz(n/2)
;else return 1+ collatz(3*n+1)


threexplusone:
	; Save callee-save registers
	; Store local variables 
	xor rax,rax
	xor rcx, rcx
		
begin: 
	cmp rdi, 1
	je return_base
even:
	mov rcx, rdi
	and rcx, 1 ; and bitwise remainder check, if the LSB of number is 1, it is odd
	cmp rcx, 1 
	je odd ; if LDB =1, it is odd and jump to odd recursive case 
	shr rdi, 1
	call threexplusone
	inc rax
	jmp return_not_base
odd: 
	lea rdi, [rdi*3+1]
	call threexplusone
	inc rax
	jmp return_not_base
return_base: 
	mov rax, 0
	ret
return_not_base: 
	ret
