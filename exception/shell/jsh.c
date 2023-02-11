#nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXARGS 10
#define MAXLINE 1024
#define __USE_GNU
void eval(char* cmdline);
int parseline(char* buf, char **argv);
int main() {
	int maxline = 1024;
	char cmdline[1024]; /*command line*/

	while(1) {
		/* read */
		printf("> ");
		fgets(cmdline,maxline,stdin);
		if(feof(stdin)) exit(0);

		/* evaluation */
		printf("evaluate %s\n",cmdline);
		eval(cmdline);
	}
}


void eval(char* cmdline){
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
			if (execve(argv[0],argv,environ) < 0) {
				printf("%s: command not found",argv[0]);
				exit(0);
			}
		}
		
		/* parent waits for fg job to terminate*/
		if(!bg) {
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
	
	if(argc == 0) return 1;

	if((bg = (*argv[argc-1] == '&' )) != 0 ) argv[--argc] = NULL;

	return bg;



}
