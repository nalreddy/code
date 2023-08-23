#include <stdio.h>
#include <limits.h>

int main()
{
	unsigned long value = 18446744073709551615ul;
	printf("SIZEOF ULONG: %lu", sizeof(unsigned long));
	printf("VALUE: %lu", value);
	printf("max %lu \n", sizeof(ULONG_MAX));

	return 0;
}
