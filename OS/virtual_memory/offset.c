#include <stdio.h>

#define KERN_PAGE_OFFSET 0xffff880000000000


int main()
{
	unsigned long va = 0xffff898431acfe35;

	printf(" %lx addree \n", va - KERN_PAGE_OFFSET);	
	return 0;
}
