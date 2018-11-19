#include <stdio.h>

#define INTERNAL_SIZE_T size_t
#define SIZE_SZ (sizeof (INTERNAL_SIZE_T))
#define fastbin_index(sz)                                 \
  ((((unsigned int) (sz)) >> (SIZE_SZ == 8 ? 4 : 3)) - 2)

int
main(void) {
	printf("%d\n", fastbin_index(0x0));
	printf("%d\n", fastbin_index(0x10));
	printf("%d\n", fastbin_index(0x20));
	printf("%d\n", fastbin_index(0x30));
	printf("%d\n", fastbin_index(0x60));
	printf("%d\n", fastbin_index(0x70));
	printf("%d\n", fastbin_index(0x7f));
	printf("%d\n", fastbin_index(0x80));
	printf("%d\n", fastbin_index(0x90));
	printf("%d\n", fastbin_index(0xa0));
	return 0;
}
