TITLE Implementation of Data Validation and Accumulator	(Project03.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 4/26/15
; Description: This program will ask user for neg number from -100 to -1 and add them all together.

INCLUDE Irvine32.inc

LOW_LIMIT = -100

.data
intro_1		BYTE	"Welcome to the Integer Accumulator", 0
intro_2		BYTE	"Programmed by James Spolsdoff", 0
prompt_1	BYTE	"What is your name? ", 0
userName	BYTE	33 DUP(0)	; string to be entered by user
intro_3		BYTE	"Hello, ", 0
intro_4		BYTE	"Enter a negative number into the accumulator between -100 and -1", 0
intro_5		BYTE	"When finished enter a non-negative integer to see your results", 0
prompt_2	BYTE	"Enter number: ", 0
inputNum	SDWORD	?
totalNum	SDWORD	0
countNum	SDWORD	0
avgNum		SDWORD	0
remainder	SDWORD	0
decimal		DWORD	0.5
result_1	BYTE	"You entered ", 0
result_2	BYTE	" valid numbers", 0
result_3	BYTE	"The sum of your valid numbers is: ", 0
result_4	BYTE	"The rounded average is: ", 0
end_1		BYTE	"Thank you for playing Integer Accumulator!", 0
end_2		BYTE	"See you soon! ", 0

.code
main PROC
	; introduction
	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf

	mov		edx, OFFSET intro_2
	call	WriteString
	call	CrLf

	; get user name
	mov		edx, OFFSET prompt_1
	call	WriteString
	mov		edx, OFFSET userName
	mov		ecx, 32
	call	ReadString

	; user instructions
	mov		edx, OFFSET intro_3
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf

	mov		edx, OFFSET intro_4
	call	WriteString
	call	CrLf

	mov		edx, OFFSET intro_5
	call	WriteString
	call	CrLf

	accLoop:	
	
		; ask user to enter the number 
		mov		edx, OFFSET prompt_2
		call	WriteString
		call	ReadInt
		mov		inputNum, eax

		; compare to see if user entered non-negative number
		cmp		eax, 0
		jg		endLoop

		; compare to see if user entered number less than -100
		cmp		eax, LOW_LIMIT
		jl		accLoop

		; add last input to the accumulator
		mov		eax, totalNum
		add		eax, inputNum
		mov		totalNum, eax
		
		; add one to the counter
		add		countNum, 1
		jmp		accLoop

	endLoop:

	; display the number of valid numbers that were entered
	mov		edx, OFFSET result_1
	call	WriteString
	mov		eax, countNum
	call	WriteDec
	mov		edx, OFFSET result_2
	call	WriteString
	call	CrLf

	; display the sum of the valid numbers entered
	mov		edx, OFFSET result_3
	call	WriteString
	mov		eax, totalNum
	call	WriteInt
	call	CrLf

	; calculate rounded average
	mov		eax, totalNum
	cdq
	mov		ecx, countNum
	idiv	ecx
	mov		avgNum, eax
	mov		remainder, edx

	mov		eax, remainder
	mov		ecx, countNum
	cdq
	idiv	ecx

	; compare to see if remainder is less or great than .5 and round accordingly
	cmp		eax, decimal
	jge		roundUp
	jmp		endRoundUp

	roundUp:
	add		avgNum, 1

	endRoundUp:

	; display the rounded average of the valid numbers that were entered
	mov		edx, OFFSET result_4
	call	WriteString
	mov		eax, avgNum
	call	WriteInt
	call	CrLf
	
	; say goodbye
	mov		edx, OFFSET end_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET end_2
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

END main