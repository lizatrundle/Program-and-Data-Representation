; University of Virginia
; CS 2150 postlab 8
; spring 2022
; Liza trundle emt8kdn
; linearSearch.s	

	global linearSearch
	section .text

; Parameter 1 is a pointer to the int array 
; Parameter 2 is the integer representing the size of the array
; Parameter 3 is the integer representing the target element to find in the array 
; Return type is int, int index if it is found and -1 if not found 
; implement function iteratively, not recursively, so jump back to top statement 
;  rdi, rsi, rdx, rcx, r8, r9 (first 6)
;since return value is an int instead of a long, only uses 32 bits instead of 64 

linearSearch:
	xor rax,rax ; zero out out the return register 
	xor r10, r10; making its at zero since they can be modified by caller
	mov r10, 0 ; int i = 0, count in array
		
loop: 
	cmp r10, rsi ; compare count with array size, have we gone through the whole array?
	je not_found ; if yes, we have iterated through array, its not found so jump to return -1
	mov ecx, [rdi+4*r10] ; move the array pointer plus the memory space times count each time 
	cmp edx, ecx ; comparing the int part of the 64 bits, comparing just the 32 bits
	je found ; target is found
	inc r10 ; i++
	jmp loop
	
not_found: 
	mov rax, -1
	ret 

found: 
	mov rax, r10 ; move in the integer representing the index of the target
	ret
	
	
	


