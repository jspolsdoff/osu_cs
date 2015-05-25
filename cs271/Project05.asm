TITLE Sorting Random Integers	(Project05.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 5/23/15
; Description: This program will get a request from a user and generate random numbers. It will then sort the numbers and print.
;				the median value.

INCLUDE Irvine32.inc

; global constants that are required by assignment parameters
MIN = 9
MAX = 200
LO = 100
HI = 900

.data
intro_1		BYTE	"Sorting Random Integers", 0
intro_2		BYTE	"Programmed by James Spolsdoff", 0
prompt_1	BYTE	"What is your name? ", 0
userName	BYTE	33 DUP(0)	; string to be entered by user
intro_3		BYTE	"Hello, ", 0
intro_4		BYTE	"This program generates random numbers in the range [100 .. 999], display the ", 0
intro_5		BYTE	"original list, sorts the list, and calculates the median value. Finally, it", 0
intro_6		BYTE	"displays the list sorted in descending order.", 0
prompt_2	BYTE	"Enter the number of random numbers to display [10 .. 200] ", 0
userNum		DWORD	?
prompt_err	BYTE	"Out of range. Enter a number between 10 and 200: ", 0

list		DWORD	MAX	DUP(?)
space		BYTE	" ", 0
curLine		DWORD	0
median_1	BYTE	"The median is ", 0
halfNum		DWORD	2
fourNum		DWORD	4

end_1		BYTE	"Results certified by James Spolsdoff", 0
end_2		BYTE	"See you soon ", 0

.code
main PROC
	call	Randomize
	
	push	OFFSET	intro_1
	push	OFFSET	intro_2
	push	OFFSET	prompt_1
	push	OFFSET	userName
	push	OFFSET	intro_3
	push	OFFSET	intro_4
	push	OFFSET	intro_5
	push	OFFSET	intro_6
	call	intro

	push	OFFSET	prompt_2
	push	OFFSET	userNum
	push	OFFSET	prompt_err
	call	getUserData

	push	OFFSET	list
	push	userNum
	call	arrayFill

	push	OFFSET	list
	push	OFFSET	space
	push	userNum
	call	displayList

	push	OFFSET list
	push	userNum
	call	sortList

	push	OFFSET list
	push	userNum
	push	OFFSET	median_1
	call	displayMedian

	push	OFFSET	list
	push	OFFSET	space
	push	userNum
	call	displayList

	push	OFFSET	end_1
	push	OFFSET	end_2
	push	OFFSET	userName
	call	farewell

	exit	; exit to operating system
main ENDP

intro			PROC
	push	ebp
	mov		ebp, esp
	
	; introduction
	mov		edx, [ebp + 36]
	call	WriteString
	call	CrLf

	mov		edx, [ebp + 32]
	call	WriteString
	call	CrLf

	; get user name
	mov		edx, [ebp + 28]
	call	WriteString
	mov		edx, [ebp + 24]
	mov		ecx, 32
	call	ReadString

	; user instructions
	mov		edx, [ebp + 20]
	call	WriteString
	mov		edx, [ebp + 24]
	call	WriteString
	call	CrLf

	mov		edx, [ebp + 16]
	call	WriteString
	call	CrLf

	mov		edx, [ebp + 12]
	call	WriteString
	call	CrLf

	mov		edx, [ebp + 8]
	call	WriteString
	call	CrLf
	
	pop		ebp		
	ret		32
intro			ENDP

getUserData		PROC
	; ask user to enter the number of random numbers
	push	ebp
	mov		ebp, esp

	mov		edx, [ebp + 16]
	call	WriteString
	call	ReadInt
	
	; check that number entered is valid
	highCheck:	; checks to make sure that numFib is <= 400
	cmp		eax, MAX
	jle		lowCheck
	mov		edx, [ebp + 8]	; ask user for another input
	call	WriteString
	call	ReadInt
	jmp		highCheck

	lowCheck:
	cmp		eax, MIN
	jg		endLoop
	mov		edx, [ebp + 8]	; ask user for another input
	call	WriteString
	call	ReadInt
	jmp		highCheck

	endLoop:

	mov		ebx, [ebp + 12]
	mov		[ebx], eax	
	
	pop		ebp
	ret		12
getUserData		ENDP

arrayFill		PROC
	push	ebp
	mov		ebp, esp

	mov		edi, [ebp + 12]
	mov		ecx, [ebp + 8]

	more:
		mov		eax, HI
		call	RandomRange
		add		eax, LO

		mov		[edi], eax
		add		edi, 4
		loop	more

	pop		ebp
	ret		8		
arrayFill		ENDP

displayList		PROC
	push	ebp
	mov		ebp, esp
	mov		edi, [ebp + 16]
	mov		ecx, [ebp + 8]
	mov		ebx, 0

	display:
		mov		eax, [edi]
		call	WriteDec
		mov		edx, [ebp + 12]
		call	WriteString
		inc		ebx
		cmp		ebx, 10
		jne		nextNum
		call	Crlf
		mov		ebx, 0
		nextNum:
		add		edi, 4
		loop	display

	call	Crlf
	call	Crlf

	pop		ebp
	ret		12
displayList		ENDP

sortList		PROC
	; using a bubble sort from Irvine text book
	push	ebp
	mov		ebp, esp
	
	mov		ecx, [ebp + 8]
	dec		ecx
	
	L1:
		push	ecx
		mov		esi, [ebp + 12]
	
	L2:
		mov		eax, [esi]
		cmp		[esi + 4], eax
		jl		L3
		xchg	eax, [esi + 4]
		mov		[esi], eax
		
	L3:
		add		esi, 4
		loop	L2
		
		pop		ecx
		loop	L1				 
	
	pop		ebp
	ret		8
sortList		ENDP

displayMedian	PROC
	push	ebp
	mov		ebp, esp
	mov		edi, [ebp + 16]

	; this is my duct tape approach to finding the median, not elegant but it works
	mov		eax, [ebp + 12]
	mov		edx, 0
	div		halfNum
	mov		edx, 0
	mul		fourNum
	add		edi, eax
	mov		eax, [edi]

	mov		edx, [ebp + 8]
	call	WriteString
	call	WriteDec

	call	Crlf
	call	Crlf

	pop		ebp
	ret		12
displayMedian	ENDP

farewell		PROC
	push	ebp
	mov		ebp, esp

	; say goodbye
	mov		edx, [ebp + 16]
	call	WriteString
	call	CrLf
	mov		edx, [ebp + 12]
	call	WriteString
	mov		edx, [ebp + 8]
	call	WriteString
	call	CrLf

	pop		ebp
	ret		12
farewell		ENDP

END main