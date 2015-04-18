TITLE Dog Years	(Project00.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 4/3/15
; Description: This program will introduce the programmer, get the user's name and age
;  calculate the user's "dog age", and report the result. 

INCLUDE Irvine32.inc

DOG_FACTOR = 7

.data
userName	BYTE	33 DUP(0)	; string to be entered by user
userAge		DWORD	?			; integer to be entered by user
intro_1		BYTE	"Hi, my name is James, I will tell you your name in dog years.", 0
prompt_1	BYTE	"What is your name? ", 0
intro_2		BYTE	"Nice to meet you, ", 0
prompt_2	BYTE	"How old are you? ", 0
dogAge		DWORD	?
result_1	BYTE	"Wow! That's ", 0
result_2	BYTE	" in dog years!", 0
goodBye		BYTE	"Good-bye, ", 0

.code
main PROC
	; introduce programmer
	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf	

	; get user name
	mov		edx, OFFSET prompt_1
	call	WriteString
	mov		edx, OFFSET userName
	mov		ecx, 32
	call	ReadString

	; get user age
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	ReadInt
	mov		userAge, eax

	; calculate user "dog years"
	mov		eax, userAge
	mov		ebx, DOG_FACTOR
	mul		ebx
	mov		dogAge, eax

	; report result
	mov		edx, OFFSET result_1
	call	WriteString
	mov		eax, dogAge
	call	WriteDec
	mov		edx, OFFSET result_2
	call	WriteString
	call	CrLf

	; say "Good-bye"
	mov		edx, OFFSET goodBye
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

END main