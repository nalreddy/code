#include<stdio.h>


int main()
{

    char *a = "aa";
    char *b = "bb";

    char **a1 = &a;
    char **b1 = &b;


    char **tmp;


    tmp = a1;
    a1 = b1;
    b1 = tmp;


    printf("a = %s b = %s \n",a, b);
    printf("a = %p b = %p \n",&a, &b);
    printf("a = %s b = %s \n",*a1, *b1);

    return 0;
}
