#include<stdio.h>

struct A
{
    char c;
    int b;
    char e;
};

int main()
{
    printf("size = %lu ", sizeof(struct A));
  return 0;
}
