#include<stdio.h>

int main()
{
	int i = 11;
	const int* ptr;

	ptr = &i;
	*ptr = 10;
	printf("i = %d\n", *ptr);

	return 0;
}
