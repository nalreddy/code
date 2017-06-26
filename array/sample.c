#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
 return (*(int *)a - *(int *)b);
}

int main()
{
 int a[] = {6,1,8,2,4,9,1}; 
 int len = sizeof(a)/sizeof(a[0]);
 int i = 0;

 qsort(a, len, sizeof(int),  cmp);

 for(i = 0; i < len ; i++)
     printf("%d  \n",a[i]);

  return 0; 
}
