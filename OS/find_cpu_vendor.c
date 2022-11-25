#include <cpuid.h>  // GCC-provided
#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#if 0
int main(void) {
    uint32_t brand[12];

    if (!__get_cpuid_max(0x80000008, NULL)) {
        fprintf(stderr, "Feature not implemented.");
        return 2;
    }

    __get_cpuid(0x80000002, brand+0x0, brand+0x1, brand+0x2, brand+0x3);
    __get_cpuid(0x80000003, brand+0x4, brand+0x5, brand+0x6, brand+0x7);
    __get_cpuid(0x80000004, brand+0x8, brand+0x9, brand+0xa, brand+0xb);
    printf("Brand: %s\n", brand);
}
#endif

#define bytes_32(num) ( ((num & 0xFF000000) >> 24) | ((num & 0x00FF0000) >> 8) | ((num & 0x0000FF00) << 8) | ((num & 0x000000FF) << 24) )
void swap(uint32_t *n) {
// Swap the nibbles of each byte.
	       *n = (*n & 0x0F0F0F0F ) << 4
	         | (*n & 0xF0F0F0F0 ) >> 4;
	      
	         // Swap the bytes of each byte pair.
	         *n = ( *n & 0x00FF00FF ) << 8
	           | ( *n & 0xFF00FF00 ) >> 8;
	      
	           // Swap the byte pairs.
	           *n = ( *n & 0x0000FFFF ) << 16
	             | ( *n & 0xFFFF0000 ) >> 16;

}
#if 0
int
main (void)
{

	  int a, b, c, d;
	  uint32_t id[3];
	  uint32_t temp;

	   // __cpuid (0, a, b, c, d);
	    __cpuid (0 /* vendor string */, a, id[0], id[1], id[2]);
	      //printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, b, c, d);
	      printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, id[0], id[1], id[2]);
	      //	      printf ("EAX: %s\nEBX: %s\nECX: %s\nEDX: %s\n", a, b, c, d);
	      id[0] =  __bswap_32(id[0]); 
	      temp =  __bswap_32(id[1]); 
	      id[2] =  __bswap_32(id[2]); 
	      id[1] = id[2];
	      id[2] = temp;

	      printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, id[0], id[1], id[2]);
	      printf("%s \n", id);
	        return 0;
}
#endif
typedef unsigned char BYTE;
void getbyte(int value, uint8_t *num, int i) {
	BYTE a, b, c, d; //to store byte by byte value

	a = (value & 0xFF); //extract first byte
	b = ((value >> 8) & 0xFF); //extract second byte
	c = ((value >> 16) & 0xFF); //extract third byte
	d = ((value >> 24) & 0xFF); 

	num[i] = d;
	num[i+1] = c;
	num[i+2] = b;
	num[i+3] = a;
}
int
main (void)
{

	  uint32_t a, x,y,z;
	  uint8_t vid[12];

	  __cpuid (0 /* vendor string */, a, x, y, z);
	  printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, x, y, z);
#if 0
	  for (int i =0; i < 3; i++) {
		  id[i]  = ( ((id[i] & 0xFF000000) >> 24) | ((id[i] & 0x00FF0000) >> 8) | ((id[i] & 0x0000FF00) << 8) | ((id[i] & 0x000000FF) << 24) );
		  printf("%x \n", id[i]);
	  }
	  x = bytes_32(x);
	  y = bytes_32(y);
	  z = bytes_32(z);
	  printf("%x \n",x);

#endif
	  getbyte(x, vid, 0);
	  getbyte(z, vid, 4);
	  getbyte(y, vid, 8);

	  printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, x, y, z);
      printf(" %s \n", vid);
	        return 0;
}
#if 0
int
main (void)
{

	  int a, b, c, d;
	  uint32_t x,y,z;
	  uint32_t temp;
	  uint32_t id[12];

	  __cpuid (0 /* vendor string */, a, id[0], id[1], id[2]);
	      //printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, b, c, d);
	      printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, id[0], id[1], id[2]);
	    
	      for (int i =0; i < 3; i++) {
		      id[i]  = ( ((id[i] & 0xFF000000) >> 24) | ((id[i] & 0x00FF0000) >> 8) | ((id[i] & 0x0000FF00) << 8) | ((id[i] & 0x000000FF) << 24) );
		     printf("%x \n", id[i]);
	      }
	      printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, id[0], id[1], id[2]);
	      printf("%s \n", id);
	        return 0;
}

#endif
