#include<stdio.h>
#include<stdlib.h>

typedef struct A
{
	int a;
	int b;
}X;

union B
{
	int a;
	char c;
};

typedef struct Var
{
	int a;
	char x[0];
}V;

int main()
{
	V *y = (V*) malloc(sizeof(V) + 2);
	y->a = 1;

	y->x[0] = 'a';
	y->x[1] = 'b';

	return 0;
}
