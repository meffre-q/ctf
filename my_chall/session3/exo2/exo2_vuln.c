// gcc exo2_vuln.c -o exo2 -no-pie -fno-stack-protector -Wl,-z,relro,-z,now,-z,noexecstack
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *binsh = "/bin/sh";

void
shell(char *str) {
  system(str);
}

int
main(void) {
  int size = 0;
  char buffer[128] = {0};

  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  memset(buffer, '\0', sizeof buffer);
  puts("Can you please give me the size of your buffer:");
  scanf("%d", &size);
  if (size <= 0) {
    puts("Newbie.");
    exit(EXIT_SUCCESS);
  }
  puts("Can you please give me your buffer:");
  read(0, buffer, size);
  buffer[strcspn(buffer, "\n")]='\0';
  printf("Thanks! Here is your buffer: %s", buffer);
  return 0;

}
