TITLE Designing Low-Level I/O Procedures	(Project06.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 5/31/15
; Description: This program will get 10 valid integers from the user and store the numeric
; values in an array. The program then displays the integers, their sum, and their average.

INCLUDE Irvine32.inc

TRUE = 1
FALSE = 0
MAX = 10

; space for the getString macro
getString macro userInput, userLength	
	LOCAL prompt
	 .data
	 prompt	BYTE	"Please enter an unsigned number: ",0
	 
	 .code
	 mov  	edx, OFFSET prompt
	 call 	WriteString
	 mov  	edx, userInput
	 mov  	ecx, userLength
	 call 	ReadString
ENDM

displayString macro userInput
	mov  	edx, userInput
	call 	WriteString
ENDM

.data

titleMsg	BYTE	"PROGRAMMING ASSIGNMENT 6: Designing Low-Level I/O Procedures", 13, 10
					BYTE	"Written By: James Spolsdoff", 13, 10, 0
introMsg	BYTE	"Please provide 10 unsigned decimal integers.", 13, 10
					BYTE	"Each number needs to be small enough to fit inside a 32 bit register.", 13, 10
					BYTE	"After you have finished inputting the raw numbers I will display a list", 13, 10
					BYTE	"of the integers, their sum, and their average value.", 13, 10, 0

errorMsg	BYTE	"ERROR: Your input was invalid. Please try again: ",13, 10, 0
space		BYTE	" ", 0

arrayNum	DWORD 	MAX	DUP(0)

divNum		DWORD	10
sum			DWORD	?
average		DWORD	?

numbersMsg	BYTE	"You entered the following numbers: ", 13, 10, 0

sumMsg		BYTE	"The sum of these numbers is: ", 13, 10, 0

averageMsg	BYTE	"The average is: ", 13, 10, 0

goodbyeMsg	BYTE	"Thanks for playing!", 13, 10, 0

testMsg		BYTE	"Just a test", 13, 10, 0

.code
main PROC
	; program introduction
	push	OFFSET	titleMsg
	push	OFFSET	introMsg
	call	intro

	; get 10 unsigned decimal integers from user
	mov  	esi, OFFSET arrayNum
	mov  	ecx, LENGTHOF arrayNum
	
	fillArray:	
		push 	OFFSET errorMsg
		call 	readVal
		pop  	[esi]
		add  	esi, 4
		loop 	fillArray
		call	Crlf

	; display the numbers
	push	OFFSET	arrayNum
	push	OFFSET	space
	push	LENGTHOF arrayNum
	push	OFFSET	numbersMsg
	call	writeVal

	; calculate and display the sum
	push	OFFSET	arrayNum
	push	LENGTHOF	arrayNum
	push	OFFSET	sumMsg
	call	displaySum

	; calculate and display the average
	push	OFFSET	arrayNum
	push	LENGTHOF	arrayNum
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
	
	mov		edx, [ebp + 16]
	call	WriteString
	call	Crlf
	mov		edx, [ebp + 12]
	call	WriteString
	call	Crlf

	pop		edx
	pop		ebp
	ret		8
intro			ENDP

readVal 		PROC 	USES edx ecx eax ebx esi

LOCAL 			userString[MAX]:BYTE, valid:DWORD

	getVal:
		lea  	eax, userString
		getString eax, LENGTHOF userString
		mov  	ebx,[ebp + 8]
		lea  	eax, userString
		push 	eax
		push 	LENGTHOF userString
		push 	ebx
		lea  	eax, valid
		push 	eax
		call 	validate
	
		mov  	eax, valid
		cmp  	eax, TRUE
		jne  	getVal
	
	lea  	eax, userString
	push 	eax
	push 	LENGTHOF userString
	call 	convertInt
	
	pop  	eax
	mov  	[ebp + 8], eax

	ret 	
readVal 		ENDP

validate 		PROC 	USES 	esi ecx edi eax

LOCAL 			limit:DWORD
	mov  	limit, 429496729 	
	
	mov  	esi, [ebp + 20]
	mov  	ecx, [ebp + 16]
	cld
	
counter:
	lodsb
	
	; check to see if the character is equal to 0
	cmp  	al, 1
	jl   	charNull
	
	; check to see if the character is equal or great than 0
	cmp  	al, "0"
	jb   	notDigit
	
	; check to see if the character is less than or equal to 9
	cmp  	al, "9"
	ja   	notDigit	
	loop 	counter
	
notDigit:
	; print out the error message for an invalid input
	mov  	edx, [ebp + 12]
	call 	WriteString
	jmp  	valDone
	
charNull:
	push 	[ebp + 20]
	push 	[ebp + 16]
	call 	convertInt
	
	pop  	eax
	cmp  	eax, limit
	jg   	notDigit
	
	mov  	eax, [ebp + 8] 	
	mov  	ebx, TRUE
	mov  	[eax],ebx
	
valDone:
	ret  	16
validate 		ENDP
	
convertInt   	PROC 	USES esi ecx edx eax

	push 	ebp
	mov  	ebp, esp
	
	mov  	esi, [ebp + 28]
	mov  	ecx, [ebp + 24]
	xor  	edx, edx
	xor  	eax, eax
	cld

vertLoop:
	lodsb
	cmp  	eax, 0
	je   	vertDone
	imul  	edx, edx, 10
	sub  	eax, "0"
	add  	edx, eax
	loop 	vertLoop

vertDone:
	mov  	[ebp + 28], edx
	pop  	ebp
	ret  	4
convertInt  	ENDP

writeVal		PROC
	push	ebp
	mov		ebp, esp
	
	mov		edi, [ebp + 20]
	mov		ecx, [ebp + 12]

	mov		edx, [ebp + 8]
	call	WriteString

	display:
		mov		eax, [edi]
		call	WriteDec
		mov		edx, [ebp + 16]
		call	WriteString
		add		edi, 4
		loop	display

	call	Crlf
	call	Crlf

	pop		ebp
	ret		16
writeVal		ENDP

displaySum		PROC	

LOCAL 			sumNum:DWORD
	mov		sumNum, 0

	push	ebp
	mov		ebp, esp

	mov		edi, OFFSET arrayNum
	mov		ecx, 10
	
	mov		edx, [ebp + 16]
	call	WriteString

	mov		edx, 0

	sumDisplay:
		mov		eax, [edi]
		add		edx, eax
		;mov	eax, [edi]
		;add	sumNum, eax
		add		edi, 4
		loop	sumDisplay

	mov		eax, edx
	mov		sum, edx
	call	WriteDec

	call	Crlf
	call	Crlf

	pop		ebp
	ret		12
displaySum		ENDP

displayAvg		PROC
	push	ebp
	mov		ebp, esp
	
	mov		edx, [ebp + 8]
	call	WriteString
	;call	Crlf

	mov		eax, sum
	mov		edx, 0
	div		divNum
	call	WriteDec
	call	Crlf
	call	Crlf

	pop		ebp
	ret		12
displayAvg		ENDP

goodbye			PROC
	push	ebp
	mov		ebp, esp
	
	mov		edx, [ebp + 8]
	call	WriteString
	call	Crlf

	pop		ebp
	ret		4
goodbye			ENDP

END main