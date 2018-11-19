// gcc exo0.c -o exo0 -no-pie -fno-stack-protector -Wl,-z,relro,-z,now
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int
main(void) {
  void (*shellcode)(void);
  int size = 0;

  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  if ((shellcode = mmap(NULL, 0xff, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) == MAP_FAILED) {
    puts("Fail mmap");
    exit(EXIT_FAILURE);
  }
  puts("Can you give me a shellcode to execute: (Max length = 0xff)");
  if ((size = read(0, shellcode, 0xff-1)) == -1) {
    puts("Fail read");
    exit(EXIT_FAILURE);
  }
  printf("Executing shellcode of size: %d\n", size);
  shellcode();
  return 0;
}
