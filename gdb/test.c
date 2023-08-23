#include <stdio.h>

int add(int a , int b)
{
	int sum = 0;

	sum = a + b;

	return sum;
}

int main()
{
	int a = 2;
	int b = 3;
	int sum = add(a, b);

	return 0;
}
