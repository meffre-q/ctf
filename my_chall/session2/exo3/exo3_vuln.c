// gcc exo3_vuln.c -o exo3 -no-pie -fno-stack-protector -Wl,-z,relro,-z,now
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int
get_int(void) {
  int value = 0;
  char buffer[6];

  memset(buffer, '\0', sizeof(buffer));
  if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    return -1;
  if (buffer[0] == '\n')
    return -1;
  buffer[strcspn(buffer,  "\n")] = '\0';
  value = atoi(buffer);
  return value;
}

int
main(void) {
  char buffer[] = "This is a string.";
  int index = 0;
  char character = 0;

  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  while (1) {
    printf("Your string: %s\n", buffer);
    puts("Which caracter index do you want to replace in this string:");
    if ((index = get_int()) == -1)
      return 1;
    puts("By which caracter do you want to replace it:");
    character = 0;
    if ((character = getchar()) == EOF)
      return 1;
    if (getchar() == EOF)
      return 1;
    buffer[index] = character;
  }
  return 0;
}
