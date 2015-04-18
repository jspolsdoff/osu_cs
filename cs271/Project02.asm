TITLE Fibonacci Numbers	(Project02.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 4/11/15
; Description: This program will calculate Fibonacci numbers based on user input.

INCLUDE Irvine32.inc



.data
intro_1		BYTE	"Fibonacci Numbers", 0
intro_2		BYTE	"Programmed by James Spolsdoff", 0
prompt_1	BYTE	"What is your name? ", 0
userName	BYTE	33 DUP(0)	; string to be entered by user
intro_3		BYTE	"Hello, ", 0
intro_4		BYTE	"Enter the number of Fibonacci terms to be displayed", 0
intro_5		BYTE	"Give the number as an integer in the range 1 to 46", 0
prompt_2	BYTE	"How many Fibonacci terms do you want? ", 0
numFib		DWORD	?
prompt_err	BYTE	"Out of range. Enter a number between 1 and 46: ", 0

message_1	BYTE	"The Fibonacci Series is", 0
preFib		DWORD	0
curFib		DWORD	1
nexFib		DWORD	1

end_1		BYTE	"Results certified by James Spolsdoff", 0
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

	; ask user to enter the number of fib numbers to display
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	ReadInt
	mov		numFib, eax

	; check that number entered is valid
	mov		eax, numFib
	errLoop:	; checks to make sure that numFib is <= 46
	cmp		eax, 47
	jl		endLoop
	mov		edx, OFFSET prompt_err	; ask user for another input
	call	WriteString
	call	ReadInt
	mov		numFib, eax
	jmp		errLoop

	endLoop:

	; display fibonacci numbers
	mov		edx, OFFSET message_1
	call	WriteString
	call	CrLf

	mov eax, nexFib	; display first fib number out of loop
	call WriteDec
	call Crlf
	
	mov ecx, numFib    ; ECX initialize with number is fib numbers to display
	sub ecx, 1

	doPart1:	; loop through calculation and display fib numbers
		mov ebx, preFib
		add ebx, curFib
		mov nexFib, ebx
		mov eax, nexFib
		call WriteDec
		call Crlf
 	
		mov eax, curFib
		mov preFib, eax
		mov eax, nexFib
		mov curFib, eax
		loop doPart1
	
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