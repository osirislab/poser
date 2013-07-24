#include <stdio.h>
#include "poser.h"

//TODO: make these actually print out the AF_UNIX etc etc
int socket(int domain, int type, int protocol) {
	printf("socket(%d, %d, %d)\n", domain, type, protocol);
}

//TODO: accept(2),  bind(2),  connect(2),  fcntl(2),  getpeername(2),  getsock‐name(2),   getsockopt(2),   ioctl(2),   listen(2),   read(2),  recv(2), select(2),  send(2),  shutdown(2),  socketpair(2),  write(2),  getpro‐toent(3), 
//ip(7), socket(7), tcp(7), udp(7), unix(7)

