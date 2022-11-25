#include<stdio.h>

void test() {
	static int i;
	i++;
	printf("%d \n",i);
}

int main() {
	test();
	test();
	test();
}
