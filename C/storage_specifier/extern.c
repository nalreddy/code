#include<stdio.h>


void printmy()
{
	extern int x;
	printf("I = %d\n", x);
}
