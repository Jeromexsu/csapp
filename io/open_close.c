#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
	int fd1, fd2;

	fd1 = open("file/foo.txt",O_RDONLY,0);
	close(fd1);
	fd2 = open("file/baz.txt",O_RDONLY,0);
	printf("fd2 = %d\n",fd2);
	close(fd2);
	exit(0);
}
