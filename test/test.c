#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ptrace.h>
#include <stdlib.h>

void bail() {
	printf("You are debugging me. Exiting.\n");
	exit(0);
}

void anti_ptrace(void) __attribute__ ((constructor));
void anti_ptrace(void) {
	if (getenv("LD_PRELOAD")) bail();
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) bail();
}



int main(int argc, char * argv[]) {
	
	printf("this is a test [%s]\n", getenv("LD_PRELOAD"));
	int fd = socket(PF_UNIX, SOCK_STREAM, 3);
	void * buf = malloc(1024);
	printf("%p\n", buf);
	printf("file descriptor = %d\n", fd);
	char * secret = crypt("password", "this is a salt");
	printf("secret = %s\n", secret);
	printf("Test END\n");
	return(0);
}
