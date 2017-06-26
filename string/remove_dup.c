#include<stdio.h>
#include<stdlib.h>
//time O(n) , constant space of array of 26
//works only for chars
//find if i have missed any corner cases
//any memory leaks
char *remove_dup(char *str) 
{
  int count[26] = {0};
  char *rem = str;
  int i = 0;

   while(*str) {
      count[*str - 'a'] += 1;
      if(count[*str - 'a'] == 1) {
         *(rem + i) = *str;
	 i++;
      }
      str++;
   }
   
   *(rem + i) = '\0';
   return rem;
}


int main(int argc, char **argv)
{
  char *str = argv[1];

  if(str == NULL) {
     printf("invalid input NULL\n");
     return 0;
  }
     
  printf("after %s\n",remove_dup(str));

  return 0;
}
