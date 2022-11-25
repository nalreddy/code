#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

int main() {
	unsigned int a; /* beginning of range */
	unsigned int b; /* end of range */
	a = 0;
	b = a;
	while (a <= b) {
		printf("number a %d\n",a);
		a++;
	}
	return 0;
}
