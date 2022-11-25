#include <cpuid.h>  // GCC-provided
#include <stdio.h>
#include <stdint.h>

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
int
main (void)
{
	  int a, b, c, d;
	    __cpuid (0 /* vendor string */, a, b, c, d);
	      printf ("EAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", a, b, c, d);
	        return 0;
}
