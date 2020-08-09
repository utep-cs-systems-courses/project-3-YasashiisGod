	.arch msp430g2553
	.p2align 1,0
/*
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
	MOV #41, R12 // 
	jmp end
four:
	MOV #71, R12
	jmp end
default:
	MOV #200, R12 //
	jmp end
end:
	RET

Jump Branch Implementation :	
*/	
	.data 			;Read/write RAM memory
STATE:	
	.word 1
JT:
	.word default		;0
	.word Case1		;1
	.word Case2		;2
	.word Case3		;3
	.word Case4		;4

	.text 			;read only memory
	.global colorTextPlacement ; visible to other object files
colorTextPlacement:
	MOV &STATE, R12
	CMP #4, R2		; s-4
	JNC default
	ADD R12,R12		; 2 * STATE
	MOV JT(R12), R0
Case1:
	MOV #41, R12
	JMP end
Case2:
	MOV #41, R12
	JMP end
Case3:
	MOV #41, R12
	JMP end
Case4:
	MOV #71, R12
	JMP end
default:
	MOV #200, R12
end:
	RET
	
	
	.global dimmerSet
dimmerSet:
	CMP.B #4, R12
	JNE bright
	MOV.B #1, R12
	JMP dim
bright:
	MOV.B #0, R12
dim:
	RET
