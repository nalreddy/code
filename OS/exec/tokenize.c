#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>

int main(int ac, char** argv) {
	char* arglist[32];
	char* command;

	char *token;                  
	token = strtok(argv[1]," ");
	if (token == NULL) {
		return -1;
	}

	command = token;
	printf("%s \n", token);
	int argc = 0;
	while(token!=NULL){
		arglist[argc]=token;      
		printf("%s \n", token);
		token = strtok(NULL," ");
		argc++;
	}

	arglist[argc]= NULL;      
	printf("%s \n", command);

	pid_t pid = fork();

	if (pid == -1) {
		printf("failed to fork\n");
	} else if (pid > 0) {
		int status;
		printf("parent waiting......\n");
		waitpid(pid, &status, 0);
		printf("done waiting......\n");
	} else  {
		char strpid[64];
		pid_t cpid = getpid();
		sprintf(strpid,"%d", cpid);

		printf("Child part\n");
		char buf[256];
		snprintf(buf, sizeof(buf), "%s%s%s", "/var/log/", strpid, "_output");
		printf("%s \n", buf);

		 int fd = open(buf, O_WRONLY|O_CREAT, 0666);
		 printf("fd %d\n",fd);
		 dup2(fd, 1);   // make stdout go to file
		 dup2(fd, 2);   // make stderr go to file - you may choose to not do this
		int status_code = execvp(command, arglist);
		if (status_code == -1) {
			printf("Process did not terminate correctly\n");
			exit(1);
		}
		close(fd);
		printf("done command.\n");
	}

	printf("This line will not be printed if execvp() runs correctly\n");
	return 0;
}
