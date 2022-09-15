#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("PID of exec_test1.c = %d\n", getpid());
	char *args[] = {"Hello", "From", "Parent", NULL};
	execv("./exec_test2", args);
	printf("Back to exec_test1.c");
	return 0;
}
