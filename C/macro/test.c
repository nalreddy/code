#include<stdio.h>

#define REG_COUNT 3   /* number of registers to read cpu vendor id */
#define VENDOR_ID_LEN ((REG_COUNT) * (4))

int main() {
	printf("leng %d\n", VENDOR_ID_LEN);

}
