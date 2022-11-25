#include<stdio.h>
#include<stdint.h>

#define VENDOR_ID_LEN 13
enum {
	AMD_CPU,
	INTEL_CPU,
	MAX_VENDOR_ID,
};

typedef uint8_t cpu[VENDOR_ID_LEN];
	
//static cpu cpu[MAX_VENDOR_ID] = { {"AuthenticAMD\0"}, {"GenuineIntel\0"} };
static cpu cpuid[MAX_VENDOR_ID] = { {"AuthenticAMD"}, {"GenuineIntel"} };

uint8_t* getcpuvendor(int cpu) {
	return cpuid[cpu];
}

int main() {
//	char cpu_vendor_id[MAX_VENDOR_ID][VENDOR_ID_LEN] = { "AuthenticAMD", "GenuineIntel" };
	//char test[2][5] = { "avcv", "fgf"};
	printf("cpu %s \n", getcpuvendor(INTEL_CPU));
}
