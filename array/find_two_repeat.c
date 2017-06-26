#include<stdio.h>

void find_xy(int *a, int n)
{
 int xor = 0;
 int set_right_most = 0;
 int i = 1;
 int x = 0,y = 0;
 
 xor = a[0];

 while( i < (n + 2)) 
 {
  xor ^=a[i];
  i++;
 }

 i = 1;

 while( i <= n)
 {
     xor ^= i;
     i++;
 }
 
 set_right_most = xor & ~(xor -1);

 printf("set_right_most bit = %d\n",set_right_most);
 
 i = 0;
 while(i < (n+2)) 
 {
  if(set_right_most & a[i])
      x ^= a[i];
  else
      y ^= a[i];
  i++;
 }

 i = 1;
 while(i <=n ) 
 {
  if(set_right_most & i)
      x ^= i;
  else
      y ^= i;
  i++;
 }

 printf("x = %d and y = %d\n",x,y);
}


int main() 
{
 int a[] = {1,2,3,3,4,4,5};

 find_xy(a, 5);
 return 0;
}
