#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char *cpu_string = "0";
	//char *cpu_string = "0,100,200,123,345";
	int i = 0, j;
	int cpu;

	printf("string %s\n", cpu_string);
	while (cpu_string[i]) {
		j = i;
		while (cpu_string[j] != ',')
			j++;
		if (cpu_string[j] == ',') {
			cpu_string[j] = 0;
			j++;
		}
	//	printf("string %s \n", cpu_string[i]);
//		cpu = atoi(&cpu_string[i]);
//		printf("cpu %d \n", cpu);

		i = j;
	}
	return 0;
}
