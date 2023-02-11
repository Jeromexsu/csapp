#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


ssize_t rio_readn(int fd, void* buf, size_t n); 
int main() {

	ssize_t count;
	char* buf = (char*) malloc(50);
	count = rio_readn(STDIN_FILENO,buf,50);
	printf("%ld characters read\n",count);
	free(buf);
}
ssize_t rio_readn(int fd, void* buf, size_t n) {
	
	size_t nleft = n;
	ssize_t nread;
	char* bufp = buf;
	while(nleft > 0) {
		nread = read(STDIN_FILENO,buf,nleft);
		if(nread < 0) {
			if(errno == EINTR) nread = 0;
			else return -1;
		} else if(nread == 0) {
			break;		
		}
		nleft -= nread;
		bufp += nread;
		printf("%d characters left\n",nleft);
	}
	return n-nleft;
}
