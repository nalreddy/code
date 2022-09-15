#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("Hello from exec_test2.c\n");
	printf("PID of exec_test2.c process is: %d\n", getpid());
	return 0;
}
