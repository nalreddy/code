#include<stdio.h>
#include<unistd.h>

int main() {
	char buffer[256];
	char *str;
	snprintf(buffer, sizeof(buffer), "%d-%d", 0, sysconf(_SC_NPROCESSORS_ONLN));
	str = buffer;
	printf("%s \n", str);
	return 0;
}
