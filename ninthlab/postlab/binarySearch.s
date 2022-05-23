; University of Virginia
; CS 2150 postlab 9
; spring 2022
; Liza trundle emt8kdn
; binarySearch.s	

	global binarySearch
	section .text

; Parameter 1 is a pointer to the int array 
; Parameter 2 is the integer representing the beginning of array 
; Parameter 3 is the integer representing the end of the array 
; parameter 4 is the integer representing the target to find in the array 
; Return type is int, int index if it is found and -1 if not found 
; implement function iteratively, not recursively, so jump back to top statement 
;  rdi, rsi, rdx, rcx, r8, r9 (first 6)
; THE FIRST FOUR PARAMETERS ARE USED IN THIS : RDI, RSI, RDX, RCX
;since return value is an int instead of a long, only uses 32 bits instead of 64 
; Int binarySearch(int arr[], int low, int high, int key)


binarySearch:
	xor rax,rax ; zero out out the return register 
	xor r10, r10; making its at zero since they can be modified by caller 
		
loop: 
	cmp rsi, rdx ; comparing low with high
	jg not_found ; if the first index is greater than the last then we are done and return -1 
	;add r10, rsi
	;add r10, rdi
	lea r10, [rsi+rdx] ; mid = low+high
	shr r10, 1 ; divide mid by two, mid = (low+high)/2
	cmp [rdi+4*r10], ecx; comparison if statement
	jg mid_more ; if a[mid]>key
	jl mid_less ; if a[mid] <key
	je equal ; if a[mid]=key
	
mid_less:
	mov rsi, r10
	inc rsi
	jmp loop
	
mid_more:
	mov rdx, r10
	dec rdx
	jmp loop	
equal:
	mov rax, r10
	ret 
not_found: 
	mov rax, -1
	ret 
	
	


