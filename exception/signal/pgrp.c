#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
	printf("Parent: pid=%d, pgrp=%d\n",getpid(),getpgrp());
	pid_t pid;

	for(int i = 0; i < 2; i++) {
		pid = fork();

		if(pid < 0) ;
		else if(pid == 0) { /*child*/
			printf("Child: pid=%d, pgrp=%d\n", getpid(),getpgrp());
			exit(0);
		}
	}

	/*reap children*/
	int status;
	while((pid = wait(&status)) > 0);
	if(errno!= ECHILD) printf("waitpid error");

	exit(0);

}
