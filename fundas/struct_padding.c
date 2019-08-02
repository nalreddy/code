#include<stdio.h>

struct A
{
    char c;
    char e;
    int b;
};

int main()
{
    printf("size = %lu ", sizeof(struct A));
  return 0;
}
