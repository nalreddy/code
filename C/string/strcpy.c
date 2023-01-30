#include<stdio.h>
#include<string.h>

int main()
{
	char src[7] = "abcdef";
	char dst[5];

	strcpy(dst, src);
	printf("dst %s \n", dst);

	return 0;
}
