.code

extern SRenderThread_CustomCommandHandler : proc
extern SRenderThread_ProcessCommands_CmdLoopTrampoline : dq
public SRenderThread_ProcessCommandsHook

SRenderThread_ProcessCommandsHook:
	; Stack frame
	push rbp
	mov rbp, rsp

	; Save all registers
	; TODO: Figure out which ones are actually used
	push rax
	push rcx
	push rdx
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	push rdi
	push rsi
	push rbx
	;push rbp
	;push rsp
	push rax ; keep 16-byte alignment

	; esi is offset into command buffer
	sub rsp, 4*8
	mov ecx, esi ; arg 0 - n ptr
	call SRenderThread_CustomCommandHandler
	add rsp, 4*8

	; Restore registers
	pop rax
	pop rbx
	pop rsi
	pop rdi
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rdx
	pop rcx
	pop rax
	leave
	jmp SRenderThread_ProcessCommands_CmdLoopTrampoline

end