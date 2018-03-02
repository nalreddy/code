#include<stdio.h>


int add(int a, int b)
{
    int sum = 0;

    sum = a + b;

    return sum;
}


int main()
{
    int a = 2, b = 3;
    int sum = 0;
    sum = add(a, b);

    printf(" sum is = %d\n", sum);

    return 0;
}
