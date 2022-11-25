#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


int main(int ac, char** argv) {
	char* arglist[32];

	char* command = "/usr/bin/ls -l -a";


#if 0
	char *token;                  
	token = strtok(command," ");
	if (token == NULL) {
		return -1;
	}

	while(token!=NULL){
		argv[argc]=token;      
		token = strtok(NULL," ");
		argc++;
	}
#endif
	pid_t pid = fork();

	if (pid == -1) {
		printf("failed to fork\n");
	} else if (pid > 0) {
		int status;
		printf("parent waiting......\n");
		waitpid(pid, &status, 0);
		printf("done waiting......\n");
	} else  {

		// Calling the execvp() system call
	//	char* arglist[] = {"du", "-h", NULL};
		int status_code = execvp(command, arglist);
		if (status_code == -1) {
			printf("Process did not terminate correctly\n");
			exit(1);
		}

		printf("done command.\n");
	}

	printf("This line will not be printed if execvp() runs correctly\n");

	return 0;
}
