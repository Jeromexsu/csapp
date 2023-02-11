#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	ssize_t count;
	char* buf = (char*) malloc(50);
	int N = 50;
	count = read(STDIN_FILENO,buf,N);

	printf("%d characters read\n", count);

}
