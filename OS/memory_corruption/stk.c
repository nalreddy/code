#include <sys/resource.h>
#include <stdio.h>

int main() {
	struct rlimit l;
	getrlimit(RLIMIT_STACK, &l);
	printf("stack_size = %ld\n", l.rlim_cur);
	return 0;
}
