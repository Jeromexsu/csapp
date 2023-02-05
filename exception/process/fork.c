#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    pid_t pid;
    
    pid = fork();
    if(pid == 0) {
	printf("child\n");
	exit(0);
    }
    else {
	printf("parent(child pid[%d])\n",pid);
	exit(0);
    }
}

