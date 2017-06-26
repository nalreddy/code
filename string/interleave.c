#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void interleave(char *str1, char *str2, char *buf, int m , int n , int len)
{

  if(m == 0 && n == 0) {
      printf("reached here\n");
      printf("buf = %s\n", buf);
      return;
  }   
  if(m != 0) {
      printf(" buf %s @m%s %s \n", str1, str2, buf);
      buf[len] = str1[0];
      interleave(str1 + 1, str2, buf, m--,n ,len++);
  }
  if(n != 0) {
      printf("buf = %s @n%s %s \n", str1, str2, buf);
      buf[len] = str2[0];
      interleave(str1, str2 + 1, buf , m , n-- ,len++);
  }
  //return;
}

int main(int argc, char **argv)
{
 char *str1 = "AB";//argv[1];
 char *str2 = "CD";//argv[2];
 int m = strlen(str1);
 int n = strlen(str2);
 char *buf = (char *) malloc(sizeof(char) *( m+ n +1));
 int i = 0;
 int len = 0;

 printf("str1 = %s and str2 = %s m = %d n = %d len = %d \n",str1, str2, m , n , m+ n +1); 
 len = m + n ;
 buf[len] = '\0';
 printf("reached\n");
 interleave(str1,str2, buf, m , n ,i);
 return 0;
}

