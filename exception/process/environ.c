#include <stdio.h>
#include <string.h>
extern char** environ;
int main() {
	printf("all environments\n");
	int i;
	char** envp = environ;
	while(strcmp(envp[i],"_=./environ")) {
		printf("%s\n",envp[i]);
		i++;
	}

}
