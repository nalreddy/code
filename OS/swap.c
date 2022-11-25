#include<stdio.h>
#include<stdint.h>
#include<byteswap.h>

int main() {
	uint32_t id = 0x68747541;
	id = __bswap_32(id);
	printf("%x \n", id);
}
