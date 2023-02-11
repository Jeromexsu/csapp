#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
ssize_t rio_readn(int fd, void* buf, size_t n) {
	size_t nleft = n;
	ssize_t nread;
	char* bufp = buf;
	while(nleft > 0) {
		if((nread)=read(fd,bufp,nleft) < 0) {
			if(errno == EINTR) nread = 0;
			else return -1;
		} else if(nread == 0) {
				printf("nread = %d\n", nread);
				break;
		}
		printf("nread = %d", nread);
		nleft -= nread;
		bufp += nread;
	}
	printf("n = %d, nleft = %d, %d\n", n,nleft,n-nleft);

	return (n-nleft);
}
