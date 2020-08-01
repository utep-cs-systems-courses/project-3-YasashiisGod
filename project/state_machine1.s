	.arch msp430g2553
	.p2align 1,0
	.text

	.global colorTextPlacement 
colorTextPlacement:
	CMP.B #1, R12
	JEQ one
	CMP.B #2, R12
	JEQ two
	CMP.B #3, R12
	JEQ three
	CMP.B #4, R12
	JEQ four
	jmp default
one:
	MOV #41, R12
	jmp end
two:
	MOV #41, R12
	jmp end
three:
	MOV #41, R12 // 29 in hex is 41
	jmp end
four:
	MOV #71, R12
	jmp end
default:
	MOV #200, R12 //200
	jmp end
end:
	RET

