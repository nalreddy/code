#include<stdio.h>

void f3(int a, int b, int c)
{
    char *s = "AAAA";

    char *x = 0;
    *x = 3;

    printf("am  f3\n");
}

void f2(int a, int b, int c)
{
    int x = 10;
    char *s = "AAAA";

    printf("am  f2\n");
    f3(4,5,6);
    printf("after f3 call am  f2\n");
}


void f1(int c, char p)
{
    int x = 10;
    char *s = "AAAA";

    printf("am  f1\n");
    f2(2,3,4);
}

int main()
{
    f1(2,'a');
    return 0;
}
