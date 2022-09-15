#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int* init_buddy(size_t size) {

	int n = ceil(log2(size));

	int *b_head = (int *) malloc(sizeof(int) * (n + 1));
	memset(b_head, 0, sizeof(int));
	b_head[n] = 1;
	return b_head;
}

void dump_buddy(int *b_head, size_t size) 
{
	int index;
	for ( index = 0; index < size; index++) {
//		printf("Slot %d status %d\n", index, b_head[index]);
		printf(" %d ", b_head[index]);
	}
	printf("\n");
}

int split(int *b_head, size_t index, size_t size)  {

	int n = ceil(log2(size));
	if (index < 0) {
		printf("failed");
		return -1;
	}
	printf("split index %d\n", index);
	b_head[index -1] = 1;
	if (n == index -1) {
		printf(" index match %d\n", index);
		return 1;
	}
	split(b_head, index - 1, size);
}

void allocate(int *b_head, size_t size) {
	int n = ceil(log2(size));
	int index;

	if (b_head[n]) {
		printf("allocated size %d at %d\n",size, n);
	}
	printf(" size %d and buddy slot %d\n", size, n);
	for(index = n + 1; index < 8; index++) {
		printf(" buddy next slot %d\n", index);
		if (b_head[index]) {
			b_head[index] = 0;
			if (split(b_head, index, size) == 1) return;
		}
	}
}

int main() {
	size_t size = 128;
	int *b_head = init_buddy(size);
	int n = ceil(log2(size));

	allocate(b_head, 30);
	dump_buddy(b_head, n + 1);
	allocate(b_head, 60);
	dump_buddy(b_head, n + 1);
	allocate(b_head, 30);
	dump_buddy(b_head, n + 1);
	allocate(b_head, 30);

	return 0;
}
