#include <cpuid.h>  // GCC-provided
#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char BYTE;
void getbyte(uint32_t value, uint8_t *num, int i) {
	BYTE a, b, c, d; //to store byte by byte value

	a = (value & 0xFF); //extract first byte
	b = ((value >> 8) & 0xFF); //extract second byte
	c = ((value >> 16) & 0xFF); //extract third byte
	d = ((value >> 24) & 0xFF); 

	printf(" %x %x %x %x \n", a, b, c ,d);
	num[i] = a;
	num[i+1] = b;
	num[i+2] = c;
	num[i+3] = d;
}
int
main (void)
{

	  uint32_t a, x,y,z;
	  //uint8_t vid[12];
	  uint8_t vid[13];

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

	  //printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, x, y, z);
	  for (int i = 0; i < 12; i++) {
		  printf("%x \n", vid[i]);
	  }
	  vid[12] = '\0';
	  char src[13];
	  src[12] = '\0';
	  memcpy(src, "AuthenticAMD", 12);
	  printf("%s \n",src);

	  //int ret = memcmp("AuthenticAMD", vid, 12);
	  int ret = strcmp("AuthenticAMD", vid);
	  if(ret > 0) {
		  printf("str2 is less than str1");
	  } else if(ret < 0) {
		  printf("str1 is less than str2");
	  } else {
		  printf("str1 is equal to str2");
	  }

	  printf(" %s \n", vid);
	  printf(" %s \n", src);
	  return 0;
}
#if 0
void getbytes(uint32_t value, uint8_t *num, int i) {
	        num[i] = (value & 0xFF);
		        num[i+1] = ((value >> 8) & 0xFF);
			        num[i+2] = ((value >> 16) & 0xFF);
				        num[i+3] = ((value >> 24) & 0xFF);
}

int isamdcpu() {
	        uint32_t a = 0,b = 0,c = 0,d = 0;
		        uint8_t vendorid[13];
			         __cpuid (0 /* vendor string */, a, b, c, d);
				          getbytes(b, vendorid, 0);
					           getbytes(d, vendorid, 4);
						            getbytes(c, vendorid, 8);
							             vendorid[12] = '\0';
								              if (!memcmp("AuthenticAMD", vendorid, 12)) {
										                       return 1;
												                } else {
															                 return 0;
																	          }
}
#endif

