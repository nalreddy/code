#include<stdio.h>

int bi_search(int *a, int low, int high,int key)
{
 int mid = -1;

 if(low <= high) {

    mid = ( low + high )/ 2;

    if(a[mid] == key) return mid;

    if(a[mid] > key) 
	return bi_search(a,low, mid - 1, key);
    else if(a[mid] < key)
	return bi_search(a, mid + 1, high, key);
 }
 return -1;
}

int main(int argc, char **argv) 
{
   int a[]= {2,5,7,8,9,10,12,15,16};
   int len = sizeof(a)/sizeof(a[0]);
   int i = 0;
   if(argc < 2) {
       printf("invalid\n");
       return;
   }    
   while( i < len) {
     printf("%d ",a[i]);
     i++;
   }
   printf("array len = %d search = %d\n",len, atoi(argv[1]));
   i = bi_search(a, 0, len - 1, atoi(argv[1]));
   if(i != -1) {
   printf("found at =%d ele = %d\n", i , a[i] );
   } else {
     printf("element not in array = %d\n", atoi(argv[1]));
   }
    return 0;
}
