#include "msrp.h"

void wait_for_request(int *fillreq) {
	int b;
	extern int fds[];
	b = read(fds[0], fillreq, sizeof(*fillreq));
	if (b != sizeof(*fillreq)) {
		perror("read pipe err");
		exit(1);
	}
}
