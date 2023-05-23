#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	void *ptr = NULL;

	ptr = (void *)sbrk(0);
	printf("addr %p \n",ptr);
}
