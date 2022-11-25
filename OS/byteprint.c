#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<byteswap.h>

int main() {
#if 0
	char amd[] = {'A', 'u', 't', 'h', 'e', 'n', 't', 'i', 'c', 'A', 'M', 'D'};
	int i = 0;
	while ( i < 12) {
		printf("%x \n", amd[i]);
		i++;
	}
#endif 
	int i;
//	uint32_t id = 0x41455678;
	uint32_t id[3];
	id [0] = 0x68747541;
	id [1] = 0x69746e65 ;
	id[2] =  0x444d4163;
#if 0
	for (i = 2; i < 3; i++) {
		id[i] = __bswap_32(id[i]);
//		printf("%x \n", id[i]);
	}
#endif
	for (i = 0; i < 3; i++) {
		printf("%x \n", id[i]);
	}

#if 0
	uint8_t val;
	for ( i = 0; i < 4; i++ ) {
		val = 0xff & x;
		x = x >> 0xff;
		printf("x = %x \n", x);
		printf("v = %x \n", val);
	}
#endif
	uint8_t *val = (uint8_t *) &id;
	for (i = 0; i < 12; i++) {
		printf("%x  i %d \n", val[i], i);

	}

	uint8_t vid[13];
	memcpy(vid, val, 12);
	vid[12] = '\0';
	printf("vendor id %s \n", vid);
	if (!memcmp("AuthenticAMD", vid, 12)) {
		printf("true \n");
		return 1;
	} else {
		return 0;
	}
}
