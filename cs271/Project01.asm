TITLE Elementary Arithmetic	(Project01.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 4/3/15
; Description: This program will introduce the programmer, ask the user for two number and calculate
;	the sum, difference, product, quotient, and remainder.

INCLUDE Irvine32.inc

.data
intro_1		BYTE	"Enter two numbers and I will show you the sum, difference, product ", 0
intro_2		BYTE	"quotient, and remainder. ", 0
prompt_1	BYTE	"What is your first number: ", 0
firstNum	DWORD	?
prompt_2	BYTE	"What is your second number: ", 0 
secondNum	DWORD	?
numSum		DWORD	?
equals_sign	BYTE	" = ", 0
plus_sign	BYTE	" + ", 0
numDif		DWORD	?
dif_sign	BYTE	" - ", 0
numPro		DWORD	?
pro_sign	BYTE	" x ", 0
numQuo		DWORD	?
quo_sign	BYTE	" / ", 0
numRem		DWORD	?
rem_sign	BYTE	" remainder ", 0
bye_1		BYTE	"Thanks for running my program! Goodbye."

.code
main PROC

	; introduce program
	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf

	mov		edx, OFFSET intro_2
	call	WriteString
	call	CrLf

	; ask user for first integer input and store
	mov		edx, OFFSET prompt_1
	call	WriteString
	call	ReadInt
	mov		firstNum, eax
	
	; ask user for second integer input and store
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	ReadInt
	mov		secondNum, eax

	; calculate sum
	mov		eax, firstNum
	add		eax, secondNum
	mov		numSum, eax
	
	; display sum
	mov		eax, firstNum
	call	WriteDec
	mov		edx, OFFSET plus_sign
	call	WriteString
	mov		eax, secondNum
	call	WriteDec
	mov		edx, OFFSET equals_sign
	call	WriteString
	mov		eax, numSum
	call	WriteDec
	call	CrLf

	; calculate difference
	mov		eax, firstNum
	sub		eax, secondNum
	mov		numDif, eax

	; display difference
	mov		eax, firstNum
	call	WriteDec
	mov		edx, OFFSET dif_sign
	call	WriteString
	mov		eax, secondNum
	call	WriteDec
	mov		edx, OFFSET equals_sign
	call	WriteString
	mov		eax, numDif
	call	WriteDec
	call	CrLf

	; calculate product
	mov		eax, firstNum
	mul		secondNum
	mov		numPro, eax

	; display product
	mov		eax, firstNum
	call	WriteDec
	mov		edx, OFFSET pro_sign
	call	WriteString
	mov		eax, secondNum
	call	WriteDec
	mov		edx, OFFSET equals_sign
	call	WriteString
	mov		eax, numPro
	call	WriteDec
	call	CrLf

	; calculate quotient & remainder
	mov		edx, 0
	mov		eax, firstNum
	div		secondNum
	mov		numQuo, eax
	mov		numRem, edx

	; display quotient
	; display remainder
	mov		eax, firstNum
	call	WriteDec
	mov		edx, OFFSET quo_sign
	call	WriteString
	mov		eax, secondNum
	call	WriteDec
	mov		edx, OFFSET equals_sign
	call	WriteString
	mov		eax, numQuo
	call	WriteDec
	mov		edx, OFFSET rem_sign
	call	WriteString
	mov		eax, numRem
	call	WriteDec
	call	CrLf

	; say goodbye
	mov		edx, OFFSET bye_1
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

END main