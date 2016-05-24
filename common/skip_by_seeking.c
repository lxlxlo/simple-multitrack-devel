
#include "common.h"

void skip_by_seeking(int fd) {

	int skipbytes;

	skipbytes = BYTES_PER_MONO_SAMP * get_skipsamps();
	
	if (skipbytes != lseek(fd, skipbytes, SEEK_SET)) {
		perror("lseek");
		exit(1);
	}
}

