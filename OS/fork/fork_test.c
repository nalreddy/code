
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/unistd.h>
void forkexample()
{
    // child process because return value zero
    if (fork() == 0) {
        printf("Hello from Child! %d ppid \n", getppid());
	printf("TGID(%d), PID(%d) : child \n", getpid(), syscall(__NR_gettid));
  
    // parent process because return value non-zero.
    } else {
        printf("Hello from Parent! ppdi %d\n",getppid());
	printf("TGID(%d), PID(%d) : Parent \n", getpid(), syscall(__NR_gettid));

    }
}
int main()
{
    forkexample();
    return 0;
}
