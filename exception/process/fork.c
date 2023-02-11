#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
void fork8();
void fork9();
void fork10();
void fork11();

int main(int argc, char* argv[]) {
	int function = atoi(argv[1]);
	switch(function) {
		case 8:
			fork8();
			break;
		case 9:
			fork9();
			break;
		case 10:
			fork10();
			break;
		case 11:
			fork11();
			break;

		default:
			exit(0);

	}
	
}

void fork8() {
		if(fork() == 0 ) {
		printf("Running Child, PID = %d\n",getpid());
		while(1);
	} else {
		printf("Terminating Parent, PID = %d\n", getpid());
		exit(0);
	}

}
void fork9(){
	int child_status;
	if(fork() == 0) {
		printf("HC: hello from child\n");
		exit(0);
	} else {
		printf("HP: hello from parent\n");
		wait(&child_status);
		printf("CT: child has terminated");
	}
	printf("Bye\n");
	exit(0);

}
void fork10() {
	int N = 10;
	pid_t pid[N];
	int i, child_status;

	for(int i = 0; i < N; i++) {
		if((pid[i] = fork())==0) {
			exit(100+i);
		}
	}

	for(int i = 0; i < N; i++) {
		pid_t wpid = wait(&child_status);
		if(WIFEXITED(child_status))
			printf("Child %d terminated with exit status %d\n",wpid,WEXITSTATUS(child_status));
		else 
			printf("Child %d terminated abnormally",wpid);
	}
}

void fork11() {
	int N = 10;
	pid_t pid[N];
	int i, child_status;

	for(int i = 0; i < N; i++) {
		if((pid[i] = fork())==0) {
			exit(100+i);
		}
	}

	for(int i = 0; i < N; i++) {
		pid_t wpid = waitpid(pid[i],&child_status,0);
		if(WIFEXITED(child_status))
			printf("Child %d terminated with exit status %d\n",wpid,WEXITSTATUS(child_status));
		else 
			printf("Child %d terminated abnormally",wpid);
	}
}
