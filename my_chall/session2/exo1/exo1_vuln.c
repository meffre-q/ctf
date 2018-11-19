// gcc exo1_vuln.c -o exo1 -no-pie -fno-stack-protector -Wl,-z,relro,-z,now
#include <stdio.h>
#include <string.h>

int
main(void) {
  char buffer[1024];

  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  memset(buffer, '\0', sizeof buffer);
  puts("Can you tell me your name:");
  gets(buffer);
  buffer[strcspn(buffer, "\n")] = 0;
  printf("Hi %s :)\n", buffer);
  return 0;
}
