#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

//#define         MAP_HASSEMAPHORE   0
#define         PG_MMAP_FLAGS   (MAP_PRIVATE|MAP_ANONYMOUS)

#define GB 1024*1024*1024
#define page_size GB
#define page_4k 4096

int main()
{
        char *ptr1, *ptr2;
        printf("hello 1\n");
	unsigned long long num_pages;
	int sts;

        unsigned long long bytes = (unsigned long long)255*page_size;
	num_pages = bytes/(unsigned long long)page_4k;

        printf("bytes =%llu, num_pages=%llu\n",bytes,num_pages);

        ptr1 = (char*)mmap(NULL, bytes, PROT_READ|PROT_WRITE, PG_MMAP_FLAGS, -1, 0);

        if (ptr1 == MAP_FAILED)
        {
		printf("map1 failed\n");
                return -1;
        }
/*
        ptr2 = (char*)mmap(NULL, bytes-page_size, PROT_READ|PROT_WRITE, PG_MMAP_FLAGS, -1, 0);

        if (ptr2 == MAP_FAILED)
        {
		printf("map2 failed\n");
                return -1;
        }
*/
	for(unsigned long long i = 0; i < num_pages; i++ )
	{

		//char x = *(ptr1 + i*(unsigned long long)page_4k);
		*(ptr1 + i*(unsigned long long)page_4k) = 1;
	}
        printf("hello 2\n");
	sts =mlockall(MCL_CURRENT);
	if (sts)
	{
		printf("failed to lock\n");
	}
        printf("hello 2-\n");
        getchar();
        printf("hello 3\n");
}

