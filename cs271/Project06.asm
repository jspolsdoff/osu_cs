TITLE Designing Low-Level I/O Procedures	(Project06.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 5/31/15
; Description: This program will get 10 valid integers from the user and store the numeric
; values in an array. The program then displays the integers, their sum, and their average.

INCLUDE Irvine32.inc

; space for the getString macro
getString		MACRO	buffer
	LOCAL	askPrompt
	.data
	askPrompt	BYTE	"Please enter an unsigned number: ", 0
	userName	DWORD	?

	.code
	push	ecx
	push	edx

	mov		edx, OFFSET askPrompt
	call	WriteString
	mov		edx, OFFSET buffer
	mov		ecx, 10
	call	ReadString

	pop		edx
	pop		ecx
ENDM

; space for the displayString macro
displayString	MACRO	string
	push	edx
	
	mov		edx, OFFSET string
	call	WriteString
	
	pop		edx
ENDM	

.data

titleMsg	BYTE	"PROGRAMMING ASSIGNMENT 6: Designing Low-Level I/O Procedures", 13, 10
					BYTE	"Written By: James Spolsdoff", 13, 10, 0
introMsg	BYTE	"Please provide 10 unsigned decimal integers.", 13, 10
					BYTE	"Each number needs to be small enough to fit inside a 32 bit register.", 13, 10
					BYTE	"After you have finished inputting the raw numbers I will display a list", 13, 10
					BYTE	"of the integers, their sum, and their average value.", 13, 10, 0

userInput	DWORD	?
array		DWORD	10 DUP (?)

sum			DWORD	?
average		DWORD	?

numbersMsg	BYTE	"You entered the following numbers: ", 13, 10, 0

sumMsg		BYTE	"The sum of these numbers is: ", 13, 10, 0

averageMsg	BYTE	"The average is: ", 13, 10, 0

goodbyeMsg	BYTE	"Thanks for playing!", 13, 10, 0

.code
main PROC
	; program introduction
	push	OFFSET	titleMsg
	push	OFFSET	introMsg
	call	intro

	; get 10 unsigned decimal integers from user
	push	array
	call	readVal
	
	; calculate the sum and average of the numbers


	; display the numbers
	push	OFFSET	numbersMsg
	call	displayNum

	; display the sum
	push	OFFSET	sumMsg
	call	displaySum

	;display the average
	push	OFFSET	averageMsg
	call	displayAvg

	;say goodbye
	push	OFFSET	goodbyeMsg
	call	goodbye

	exit	; exit to operating system
main ENDP

; this is where all my proc go
intro			PROC
	push	ebp
	push	edx
	mov		ebp, esp
	
	mov		edx, [ebp+16]
	call	WriteString
	call	Crlf
	mov		edx, [ebp+12]
	call	WriteString
	call	Crlf

	pop		edx
	pop		ebp
	ret		8
intro			ENDP

readVal			PROC
	push	ebp
	mov		ebp, esp

	mov		edi, [ebp + 8]
	mov		ecx, 10

	fillArray:
		getString userInput
		; test the validation proc
		mov		edx, OFFSET userInput
		xor eax, eax ; zero a "result so far"
		top:
		movzx ecx, byte [edx] ; get a character
		inc edx ; ready for next one
		cmp ecx, '0' ; valid?
		jb done
		cmp ecx, '9'
		ja done
		sub ecx, '0' ; "convert" character to number
		imul eax, 10 ; multiply "result so far" by ten
		add eax, ecx ; add in current digit
		jmp top ; until done
		done:
		;

		add		edi, 4
		loop	fillArray

	pop		ebp
	ret		4
readVal			ENDP

writeVal		PROC
	push	ebp
	mov		ebp, esp

	mov		edi, [ebp + 8]
	mov		ecx, 10

	printArray:
		; displayString [edi]
		
		add		edi, 4
		loop	printArray

	pop		ebp
	ret		4
writeVal		ENDP

displayNum		PROC
	push	ebp
	mov		ebp, esp
	
	mov		edx, [ebp+8]
	call	WriteString
	call	Crlf

	pop		ebp
	ret		4
displayNum		ENDP

displaySum		PROC
	push	ebp
	mov		ebp, esp
	
	mov		edx, [ebp+8]
	call	WriteString
	call	Crlf

	pop		ebp
	ret		4
displaySum		ENDP

displayAvg		PROC
	push	ebp
	mov		ebp, esp
	
	mov		edx, [ebp+8]
	call	WriteString
	call	Crlf

	pop		ebp
	ret		4
displayAvg		ENDP

goodbye			PROC
	push	ebp
	mov		ebp, esp
	
	mov		edx, [ebp+8]
	call	WriteString
	call	Crlf

	pop		ebp
	ret		4
goodbye			ENDP

END main