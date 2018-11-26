#include<stdio.h>

void show_mem_rep(char *start, int n) 
{
        int i;
	    for (i = 0; i < n; i++)
		         printf(" addr @ i %d, %p %.2x", i, start + i, start[i]);
	        printf("\n");
}

/*Main function to call above function for 0x01234567*/
int main()
{
       int i = 0x01234567;
          show_mem_rep((char *)&i, sizeof(i));
#if 0
	  unsigned int i = 1;
	  char *c = (char *) &i;
          printf(" addr of i = %p  val = %x \n", c, *c);

          show_mem_rep((char *)&i, sizeof(i));

	  if(*c)
	       printf("little endian\n");
	  else
	      printf("big boy\n");

#endif
          return 0;
}
