#include<stdio.h>

int first_search(int *a, int low, int high,int key)
{
 int mid = -1;

 if(low <= high) {

    mid =low +  ( high - low )/ 2;

    if(((mid == 0) ||  (key >  a[mid -1 ])) && (a[mid] == key)) {
	printf("mid = %d and a[mid -1 ] = %d and a[mid] = %d\n",mid,a[mid-1],a[mid]);
	return mid;
    }
    printf("mid = %d and a[mid ] = %d\n",mid, a[mid]);
    if(key > a[mid]) 
	return first_search(a, mid +1,  high, key);
    else 
	return first_search(a, low, mid - 1, key);
 }
 return -1;
}

int main(int argc, char **argv) 
{
   int a[]= {1,2,2,3,4,6,6,6,7};
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
   i = first_search(a, 0, len - 1, atoi(argv[1]));
   if(i != -1) {
   printf("found at =%d ele = %d\n", i , a[i] );
   } else {
     printf("element not in array = %d\n", atoi(argv[1]));
   }
    return 0;
}
