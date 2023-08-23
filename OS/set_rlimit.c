#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int ac, char **argv)
{
    struct rlimit r = {RLIM_INFINITY, RLIM_INFINITY};

    if (setrlimit(RLIMIT_MEMLOCK, &r)) {
        perror("setrlimit(RLIMIT_MEMLOCK)");
        return -1;
	}
	printf("sucess \n");
	return 0;
}
