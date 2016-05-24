#include "msrp.h"

void setup_pipe() {
	extern int fds[];
	if (-1 == pipe(fds)) {
		perror("srp setup_pipe()\n");
		exit(1);
	}
}
		
