#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 26

void anagram (char *str1, char *str2, int *count, int m, int n) 
{
  int mask[26] = {0};
  int i = 0;
  char *ptr = NULL;

  while(*str1){
  //    printf("str = %s\n",str1);
      ptr = str1; 
      i = 0;
      while( i < n) {
//	  printf("ptr = %s\n",ptr);
           mask[*ptr - 'a']++;
	   i++;
	   ptr++;
      }
      i = 0;
#if 0
      while( i < MAX) {
	  printf(" i = %d mask = %d and count = %d\n",i , mask[i],count[i]);
	  i++;
      }
      i = 0;
#endif      
      while((mask[i] == count[i] )&& i < MAX)
      { 
//	  printf(" mssk i = %d and count i = %d i = %d \n", mask[i], count[i], i);
	  i++;
      }
      printf("i = %d \n" ,i);
      if(i == MAX) printf("found anagram at %s \n", str1);
      str1++;
      i = 0;
      while( i < MAX) {
	 mask[i] = 0;
	 i++;
      }
      i = 0;
  }
  return ; 
}

int main(int argc, char **argv)
{
 char *str1 = argv[1];
 char *str2 = argv[2];
 char *temp = str2;

 int m = strlen(str1);
 int n = strlen(str2);
 int i = 0;

 printf("str1 = %s and str2 = %s\n",str1, str2); 
 int *count = (int *) malloc(sizeof(int) * MAX );

 if(!count) {
    printf("count no memory\n");
    return;
 }   

 while(*temp) {
  count[*temp - 'a']++;
  temp++;
 }

 printf("reached 1\n");
 anagram(str1, str2, count, m , n);

}

