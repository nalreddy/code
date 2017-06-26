#include <stdio.h>

int main() {
  // int q[] = {3000,4096,4096,320};
   int q[] = {3980,4096,4096,116};
  // int r[] = {1500,2456,1234,4429,434,3005,454};
   int r[] = {4096,4096,4096};
//  int r[] = {3000};
   int i = 0, j = 0;
   int get_opq = 1;
   int get_rec = 1;
   int num_entries = sizeof(q)/sizeof(q[0]);
   int total_rec = 0;
   int total_opq = 0;
   int max_size = 20000;
   int rec_size = 0;
   int opq_rem = 0;
   int get_log = 1;
   int log = 0;
   int LOG_SIZE = 40;

    for(i = 0, j = 0; i < num_entries; ) {
     // handle size cases
       if(get_opq == 1) {
          opq_rem = q[i];
          printf("get_opq = %d  count = %d\n",opq_rem, i);
       }    
       if(get_rec == 1) {
          if(get_log == 1) {
             if((LOG_SIZE - offset) >= opq_rem) {
                
             }                         
          }
          rec_size = r[j];
          printf("get_rec = %d and count = %d\n", rec_size, j);
       }  
       //handle last opq and rec cases
       if(rec_size >= opq_rem) {
          total_rec += rec_size;
          rec_size -=opq_rem;
          opq_rem = 0;
          printf("rec_size > = %d\n", rec_size);
        } else {
          total_opq += opq_rem;
          opq_rem -= rec_size;
          rec_size = 0;    
          printf("opq_rem > = %d\n", opq_rem);
       }
       
       if(opq_rem ==0 ) {
          get_opq = 1;
          printf("consumed opqa number = %d\n",i);
          i++;          
       } else {
         get_opq = 0;
       }

       if(rec_size == 0) {
          get_rec = 1;
          printf("formed record number = %d\n",j);
          j++;
       } else {
         get_rec = 0;
       } 
                       
   }   
   return 0;
} 
