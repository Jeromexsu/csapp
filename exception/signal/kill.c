/* fork 10 child processes, use kill -9 pid to send signal */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define n 10
int main() {
	int i;
	pid_t pid;
	for(i = 0; i < n; i++) {
		/* parent process */
		if((pid = fork()) > 0 ) {	
		}
		/* child */
		else if(pid == 0){
		//    printf("pid: %d,process group: %d\n",getpid(),getpgrp());
			exit(0);
		}
	}
	while(1);
}
