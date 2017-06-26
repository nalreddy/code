#include<stdio.h>

#if 0
void show_mem_rep(char *start, int n) 
{
        int i;
	    for (i = 0; i < n; i++)
		         printf(" %.2x", start[i]);
	        printf("\n");
}

#endif
/*Main function to call above function for 0x01234567*/
int main()
{
#if 0
       int i = 0x01234567;
          show_mem_rep((char *)&i, sizeof(i));
#endif
	  unsigned int i = 1;
	  char *c = (char *) &i;
	  if(*c)
	       printf("little endian\n");
	  else
	      printf("big boy\n");
	  getchar();
	        return 0;
}
