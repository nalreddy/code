#include<stdio.h>
#include<stdlib.h>

struct test
{
    int x;
};
void f(struct test **ptr)
{
    struct test *p = (struct test *) malloc(sizeof(struct test));

    p->x = 10;
    *ptr = p;
}

void main()
{
    struct test *ptr = NULL;

    f(&ptr);

    printf(" val = %d \n", ptr->x);

    printf("ptr = %p  \n", ptr);
    free(ptr);
    printf("ptr = %d  \n", ptr->x);

    int *p = malloc(sizeof(int));

    *p = 123;
    free(p);
    if (p)
        printf("still p = %d", *p);
}
