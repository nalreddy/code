#include<stdio.h>
#include<stdlib.h>

void f(int* ptr) {
	*ptr = 10;
}
int main() {
	int* ptr = (int *) malloc(sizeof(int));
	f(ptr);
	printf("%d \n", *ptr);
	return 0;
}
