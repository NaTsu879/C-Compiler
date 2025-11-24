.MODEL SMALL
.STACK 100h
.DATA
number DB "00000$" 
w DW 10 DUP (0)
.CODE
main PROC			; Line 2
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	PUSH 0			; Line 4
	SUB SP ,20			; Line 5
	PUSH 0			; Line 6
	PUSH 2			; Line 6
	POP AX			; Line 6
	NEG AX
	POP BX
	PUSH AX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	POP AX
	MOV w[BX], AX
	PUSH 0			; Line 7
	PUSH 0			; Line 7
	POP BX			; Line 7
	SHL BX, 1 
	MOV AX, w[BX]
	POP BX
	PUSH AX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	POP AX
	MOV SI, BX 
	NEG SI
	MOV [BP+SI], AX
	PUSH 0			; Line 8
	POP BX			; Line 8
	SHL BX, 1
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	MOV SI, BX 
	NEG SI
	MOV AX, [BP+SI]
	MOV [BP-2], AX
	MOV AX, [BP-2]
	CALL print_output			; Line 9
	CALL new_line
	PUSH 1			; Line 10
	PUSH 0			; Line 10
	POP BX			; Line 10
	SHL BX, 1 
	MOV AX, w[BX]
	PUSH AX 
	INC AX 
	MOV w[BX], AX
	POP AX			; Line 10
	POP BX
	PUSH AX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	POP AX
	MOV SI, BX 
	NEG SI
	MOV [BP+SI], AX
	PUSH 1			; Line 11
	POP BX			; Line 11
	SHL BX, 1
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	MOV SI, BX 
	NEG SI
	MOV AX, [BP+SI]
	MOV [BP-2], AX
	MOV AX, [BP-2]
	CALL print_output			; Line 12
	CALL new_line
	PUSH 0			; Line 13
	POP BX			; Line 13
	SHL BX, 1 
	MOV AX, w[BX]
	MOV [BP-2], AX
	MOV AX, [BP-2]
	CALL print_output			; Line 14
	CALL new_line
	PUSH [BP-2]		; Line 16
	PUSH 0			; Line 16
	POP BX			; Line 16
	POP AX
	ADD AX, BX
	MOV [BP-2], AX
	PUSH [BP-2]		; Line 17
	PUSH 0			; Line 17
	POP BX			; Line 17
	POP AX
	SUB AX, BX
	MOV [BP-2], AX
	PUSH [BP-2]		; Line 18
	PUSH 1			; Line 18
	POP BX			; Line 18
	POP AX
	MUL BX
	MOV [BP-2], AX
	MOV AX, [BP-2]
	CALL print_output			; Line 19
	CALL new_line
	PUSH [BP-2]		; Line 21
	PUSH 0			; Line 21
	POP BX 			; Line 21
	POP AX 
	CMP AX, BX
	JG L1
	PUSH 0
	JMP L2
L1:
	PUSH 1
L2:

	PUSH [BP-2]		; Line 21
	PUSH 10			; Line 21
	POP BX 			; Line 21
	POP AX 
	CMP AX, BX
	JL L3
	PUSH 0
	JMP L4
L3:
	PUSH 1
L4:

	POP BX 			; Line 21
	POP AX 
	CMP BX, 0
	JE L5
	CMP AX, 0
	JE L5
	PUSH 1
	JMP L6
L5:
	PUSH 0
L6:

	PUSH [BP-2]		; Line 21
	PUSH 0			; Line 21
	POP BX 			; Line 21
	POP AX 
	CMP AX, BX
	JL L7
	PUSH 0
	JMP L8
L7:
	PUSH 1
L8:

	PUSH [BP-2]		; Line 21
	PUSH 10			; Line 21
	POP AX			; Line 21
	NEG AX
	PUSH AX
	POP BX 			; Line 21
	POP AX 
	CMP AX, BX
	JG L9
	PUSH 0
	JMP L10
L9:
	PUSH 1
L10:

	POP BX 			; Line 21
	POP AX 
	CMP BX, 0
	JE L11
	CMP AX, 0
	JE L11
	PUSH 1
	JMP L12
L11:
	PUSH 0
L12:

	POP BX 			; Line 21
	POP AX 
	OR BX, AX
	CMP BX, 0
	JNE L13
	PUSH 0
	JMP L14
L13:
	PUSH 1
L14:

	POP AX			; Line 21
	CMP AX, 0
	JE L15
	PUSH 100			; Line 22
	POP AX			; Line 22
	MOV [BP-2], AX
	JMP L16
L15:
	PUSH 200			; Line 24
	POP AX			; Line 24
	MOV [BP-2], AX
L16:
	MOV AX, [BP-2]
	CALL print_output			; Line 25
	CALL new_line
	PUSH 0			; Line 27
	POP AX			; Line 27
L17:
	ADD SP, 22
	POP BP
	MOV AX, 4C00H
	INT 21H
MAIN ENDP
new_line proc
    push ax
    push dx
    mov ah,2
    mov dl,0Dh
    int 21h
    mov ah,2
    mov dl,0Ah
    int 21h
    pop dx
    pop ax
    ret
    new_line endp
print_output proc  ;print what is in ax
    push ax
    push bx
    push cx
    push dx
    push si
    lea si,number
    mov bx,10
    add si,4
    cmp ax,0
    jnge negate
print:
    xor dx,dx
    div bx
    mov [si],dl
    add [si],'0'
    dec si
    cmp ax,0
    jne print
    inc si
    lea dx,si
    mov ah,9
    int 21h
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret
negate:
    push ax
    mov ah,2
    mov dl,'-'
    int 21h
    pop ax
    neg ax
    jmp print
    print_output endp
END main
