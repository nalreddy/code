#include<stdio.h>
#include <limits.h>

#define dword_t 8

int main()
{
	int BITS_PER_DWORD = sizeof(dword_t) * CHAR_BIT;
	printf("val = %d \n", BITS_PER_DWORD);

}
