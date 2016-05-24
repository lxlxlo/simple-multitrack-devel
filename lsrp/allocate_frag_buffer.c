#include "lsrp.h"

void allocate_frag_buffer(char **frag_ptr, int fragsize) {
	if ((*frag_ptr = malloc(fragsize)) == NULL) {
		perror("frag malloc");
		exit(1);
	}
}

