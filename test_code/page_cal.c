#include<stdio.h>

int main()
{
	unsigned long vaddr, base;
	unsigned long base_page_size = 4 * 1024;
	
	base = vaddr = 0x56114f0e1234;
	base &=~(base_page_size - 1);

	printf("vadd %lx base %lx \n",vaddr, base);
	return 0;
}
