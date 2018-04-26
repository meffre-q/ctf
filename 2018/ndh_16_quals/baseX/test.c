#include <string.h>
#include <stdio.h>

long long
calc_rand(int num, int str_len) {
    long long result;
    int i;
    long long tmp;

    if (str_len) {
        tmp = num;
        for ( i = 0; i < str_len - 1; ++i )
          tmp *= num;
        result = tmp;
    }
    else
        result = 1LL;
    return result;
}

long long
encode(const char *str) {
    long long num_int;
    int index = 0;
    long long result = 0;
    int str_len;

    str_len = strlen(str);
    while (str[index]) {
        if ( str[index] <= '/' || str[index] > 'N' )
            return result;
        num_int = str[index] - '0';
        --str_len;
        result += num_int * calc_rand(31, str_len);
        ++index;
    }
    return result;
}

long long
decode(const char *str) {
  long long num_int;
  int index = 0;
  long long result = 0;
  int str_len;

  str_len = strlen(str);
  while (num>0) {
    if ( str[index] <= '/' || str[index] > 'N' )
      return result;
    num_int = str[index] - '0';
    --str_len;
    result += num_int * calc_rand(31, str_len);
    ++index;
  }
  return result;
}


int
main(int ac, char **av) {
    printf("%s\n", av[1]);
    printf("0x%016x\n", encode(av[1]));
    //    printf("0x%016x\n", decode(av[1]));
    return 0;
}
