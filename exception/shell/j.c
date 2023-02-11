#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "../../error_handle.h"
#define MAXARGS 10
#define MAXLINE 1024
#define __USE_GNU
extern char** environ;
typedef void (*sighandler_t)(int);


volatile sig_atomic_t fg_pid;

void eval(char* cmdline);
int parseline(char* buf, char **argv);
void sigint_handler(int sig) {
	write(STDOUT_FILENO,"\n",1);
	if(fg_pid) {
		kill(fg_pid,9);
		fg_pid = 0;
	} else {
		write(STDOUT_FILENO,">",2);
	}
	//_exit(0);
}


int main() {
	int maxline = 1024;
	char cmdline[1024]; /*command line*/
    /*intall signal handler*/
	sighandler_t prev_sigint_handler = signal(SIGINT,sigint_handler);
	if(prev_sigint_handler == SIG_ERR) unix_error("SIG_ERR");
	while(1) {
		/* read */
		printf("> ");
		fgets(cmdline,maxline,stdin);
		if(feof(stdin)) exit(0);

		/* evaluation */
		eval(cmdline);
	}
}


void eval(char* cmdline){
	extern char** environ;
	char *argv[MAXARGS];
	char buf[MAXLINE];
	int bg;				/* should the job run in bg or fg? */
	pid_t pid;

	strcpy(buf,cmdline);
	
	bg = parseline(buf,argv);
	
	/* no argv, return */
	if(argv[0] == NULL) return;
	
	/* exec command(argv[0]) */
	if(1) {
		if((pid = fork()) == 0) { /*child process execute the program */
			
			if (execvpe(argv[0],argv,environ) < 0) {
				unix_error("execve");
				printf("%s: command not found\n",argv[0]);
				exit(0);
			}
		}
		
		/* parent waits for fg job to terminate*/
		if(!bg) {
			fg_pid = pid;
			int status;
		//	if(waitpid(pid,&status,0) < 0) unix_error("waitfg: waitpid error");
	//		else printf("%d %s",pid, cmdline);
			waitpid(pid,&status,0);
		}
	} 

	return;
}

int parseline(char* buf, char **argv) {
	char *delim; /*points to first space */
	int argc;
	int bg;
    /* preprocess */
	buf[strlen(buf) - 1] = ' '; /*replace trailing \n with space */
	while(*buf && (*buf == ' ' )) buf++; /*ignore leading space*/
	
	/* build argv*/
	argc = 0;
	while((delim = strchr(buf, ' '))) {
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while(*buf && (*buf == ' ')) buf++;
	}
	argv[argc] = NULL;
	if(argc == 0) return 1;

	if((bg = (*argv[argc-1] == '&' )) != 0 ) argv[--argc] = NULL;

	return bg;

}
