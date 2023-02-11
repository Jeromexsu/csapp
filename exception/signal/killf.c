#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <wait.h>
#define N 5
int main() {
	pid_t pid[N];
	/* fork N child */
	for(int i = 0; i < N; i++) {
		if((pid[i]=fork()) == 0) while(1);
	}

	/* send interrupt signal */
	for(int i = 0; i < N; i++) {
		printf("Killing process %d\n",pid[i]);
		kill(pid[i],SIGINT);
	}

	/*reap all chilren */
	for(int i = 0; i < N; i++) {
		int status;
		pid_t wpid = wait(&status);
	}
}
