#include<stdlib.h>
#include<stdio.h>

int main()
{
    void *ptr = NULL;

    int ret =  posix_memalign(&ptr, 128, 4);

    printf(" %p " , ptr);

    if (ptr)
        free(ptr);

    return 0;
}
