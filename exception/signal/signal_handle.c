#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "../../error_handle.h"
typedef void (*sighandler_t)(int);

void sigint_handler(int sig) {
	printf("\nCaught SIGINT!\n");
	exit(0);
}
int main() {
	sighandler_t prev_handler;
	prev_handler = signal(SIGINT,sigint_handler);
	if(prev_handler == SIG_ERR) unix_error("signal error");
	pause();

	return 0;

}
