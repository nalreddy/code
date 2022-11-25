#include <string.h>
#include <stdio.h>
#include<stdlib.h>

int main () {
   char *str = "0,1,2-4";
   char *token;
   
   char buf[20];

   strcpy(buf, str);
   /* get the first token */
   token = strtok(buf, ",-");
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      int cpu = atoi(token);

      printf("cpu %d",cpu);
      token = strtok(NULL, ",-");
   }
   
   return(0);
}
