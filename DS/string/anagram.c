#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 26

int anagram (char *str1, char *str2, int *count) 
{
   int i = 0;

   printf("reached 2 str = %s and str2 = %s\n", str1,str2);
   while(*str1 && *str2) {
      printf("str1 = %s and str2 = %s\n",str1, str2); 
      count[*str1 - 'a']++;
      count[*str2 - 'a']--;
      str1++;
      str2++;
   }
   if(*str1 || *str2) {
      printf("am here str = %s and str 2= %s\n", str1, str2);
       return 0;
   }

   while( i < 26){
       if(count[i]) {
	   printf("am here too %c\n",count[i]); 
	   return 0;
       }   
       i++;
   }

  return 1; 
}

int main(int argc, char **argv)
{
 char *str1 = argv[1];
 char *str2 = argv[2];

 printf("str1 = %s and str2 = %s\n",str1, str2); 
 int *count = (int *) malloc(sizeof(int) * MAX );

 if(!count) {
    printf("count no memory\n");
    return;
 }   
 printf("reached 1\n");
 if(anagram(str1, str2, count)){
    printf("str1 = %s and str2 = %s anagrams\n",str1, str2);
 } else {
    printf("str1 = %s and str2 = %s not anagrams\n",str1, str2);
 }

}

