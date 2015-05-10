TITLE Composite Number Calculator	(Project04.asm)

; Author: James Spolsdoff
; Course/project ID: CS 271
; Date: 5/9/15
; Description: This program will calculate composite numbers based on a users input from 1 to 400.

INCLUDE Irvine32.inc

HIGH_LIMIT = 401

.data
intro_1		BYTE	"Composite Numbers", 0
intro_2		BYTE	"Programmed by James Spolsdoff", 0
prompt_1	BYTE	"What is your name? ", 0
userName	BYTE	33 DUP(0)	; string to be entered by user
intro_3		BYTE	"Hello, ", 0
intro_4		BYTE	"Enter the number of composite numbers you would like to see.", 0
intro_5		BYTE	"I'll accept orders for up to 400 composites.", 0
prompt_2	BYTE	"Enter the number of composites to display [1 .. 400] ", 0
numComp		DWORD	?
prompt_err	BYTE	"Out of range. Enter a number between 1 and 400: ", 0

compFlag	DWORD	0
compShown	DWORD	0
space		BYTE	" ", 0
lineMax		DWORD	10
curLine		DWORD	0
currentNum	DWORD	5

end_1		BYTE	"Results certified by James Spolsdoff", 0
end_2		BYTE	"See you soon! ", 0

.code
main PROC
	call	intro

	call	getUserData

	call	showComposites

	call	farewell

	exit	; exit to operating system
main ENDP

intro			PROC
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
	ret
intro			ENDP

getUserData		PROC
	; ask user to enter the number of composite numbers to display
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	ReadInt
	mov		numComp, eax
	call	validate
	ret
getUserData		ENDP

validate		PROC
	; check that number entered is valid
	mov		eax, numComp
	highCheck:	; checks to make sure that numFib is <= 400
	cmp		eax, HIGH_LIMIT
	jl		lowCheck
	mov		edx, OFFSET prompt_err	; ask user for another input
	call	WriteString
	call	ReadInt
	mov		numComp, eax
	jmp		highCheck

	lowCheck:
	cmp		eax, 0
	jg		endLoop
	mov		edx, OFFSET prompt_err	; ask user for another input
	call	WriteString
	call	ReadInt
	mov		numComp, eax
	jmp		lowCheck

	endLoop:
	ret
validate		ENDP

showComposites	PROC
	
	mov		eax, numComp
	cmp		eax, 1
	je		justOne
	mov		eax, 4
	call	WriteDec
	mov		edx, OFFSET space
	call	WriteString	

	compositeLoop:
		mov		compFlag, 0
		call	isComposite
		cmp		compFlag, 1
		je		displayComp
		inc		currentNum
		inc		compShown
		mov		eax, compShown
		cmp		eax, numComp
		jl		compositeLoop
		jmp		done 

	displayComp:
		mov		eax, 0
		mov		eax, currentNum
		call	WriteDec
		mov		edx, OFFSET space
		call	WriteString
		inc		currentNum
		inc		curLine
		mov		edx, 0
		mov		eax, curLine
		div		lineMax
		cmp		edx, 0
		je		newLine
		jmp		compositeLoop

	newLine:
		call	Crlf
		jmp		compositeLoop

	justOne:
		mov		eax, 4
		call	WriteDec

	done:
		call	Crlf
	ret
showComposites	ENDP

isComposite	PROC
	mov		ecx, 0
	mov		ecx, currentNum

	compCheck:
		dec		ecx
		cmp		ecx, 1
		je		done
		mov		edx, 0
		mov		eax, currentNum
		div		ecx
		cmp		edx, 0
		je		isComp
		jmp		compCheck

	isComp:
	mov		compFlag, 1
	jmp		done

	done:
		ret
isComposite		ENDP

farewell		PROC
	; say goodbye
	mov		edx, OFFSET end_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET end_2
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf
	ret
farewell		ENDP

END main