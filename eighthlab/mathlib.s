; mathlib.s

;Liza trundle emt8kdn prelab 8 
; inspo from PDR lab 8 instructions: vecsum 
; Purpose : This file contains the implementation of the function
;        product, which multiplies two integers.
;		power, which computes power of two integers. 
; product must only use addition and iteration
; power must only use the product function and recursion
	
	global _product
	
	global _power

	section .text
	
_product:
    	; prologue: 
   	; Parameter 1 (in rdi) is the value of passed in parameter x (integer 1)
	; Parameter 2 (in rsi) is the value of passed in parameter y (integer 2)
	;Return value for product: is a long that is the product of 2 integers 
	;i starts at zero, and i goes until it reaches the second number, so since you cant use multiplication, you are adding the number in x to the register (rax-- which is zero) y times 
	
	; subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i , use r10 to be modified by callee even when not given as parameter 
		
start:	
	cmp	r10, rsi	 ; does i == second parameter (which is y)
	je	done		 ; if so, we are done with the loop that multiplies the two numbers
	add	rax, rdi	; adding the value of rdi to register which currently == zero
	inc	r10		 ; increment our counter i
	jmp	start	; we are done with this loop iteration
done:	
	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return, returns what is in the rax return register rn 
	ret
		
_power:
	;prologue: 
   	; Parameter 1 (in rdi) is the value of passed in parameter x (base)
	; Parameter 2 (in rsi) is the value of passed in parameter y (exponenet)
	;Return value for product: is a long that is the power of 2 integers
	xor	rax, rax	 ; zero out the return register, 
begin:
	mov	rax,1 ; move value of one into acc to return if base case is true, also anything to the zero should be 1 		
	cmp	rsi, 0	 ; does the exponent =0? 
	je return   ; return what is in RAX which one 1, which is what we return if base case true initially
recursive_case:
	dec rsi
	call _power   ; on the same parameters just with the exponent decremented 
	mov	rsi, rax	;move the return value of power into the second parameter, and then call product on that with param 1)
	call _product
return:
	ret 