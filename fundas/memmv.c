How to implement memmove()?

The trick here is to use a temp array instead of directly copying from src to dest. The use of temp array is important to handle cases when source and destination addresses are overlapping.

//C++ program to demonstrate implementation of memmove()
#include<stdio.h>
#include<string.h>
 
// A function to copy block of 'n' bytes from source
// address 'src' to destination address 'dest'.
void myMemMove(void *dest, void *src, size_t n)
{
   // Typecast src and dest addresses to (char *)
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
 
   // Create a temporary array to hold data of src
   char *temp = new char[n];
 
   // Copy data from csrc[] to temp[]
   for (int i=0; i<n; i++)
       temp[i] = csrc[i];
 
   // Copy data from temp[] to cdest[]
   for (int i=0; i<n; i++)
       cdest[i] = temp[i];
 
   delete [] temp;
}
 
// Driver program
int main()
{
   char csrc[100] = "Geeksfor";
   myMemMove(csrc+5, csrc, strlen(csrc)+1);
   printf("%s", csrc);
   return 0;
}
