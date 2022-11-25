#include<stdio.h>

#define CCMD_PAGE_SIZE (4096)

int main() {
	unsigned long key = 0xFFFF8456;
	key &= ~(CCMD_PAGE_SIZE - 1);
	printf("key %x ccmd %x \n ", key,  ~(CCMD_PAGE_SIZE - 1));
	return 0;
}
