
#include "mix.h"

void allocate_outbuf(short **outbuf, int nocs, int *outbufbytes) {
	*outbufbytes = INBUFELEMS * sizeof(short) * nocs;
	if (NULL == (*outbuf = malloc(*outbufbytes))) {
		perror("malloc for outbuf");
		exit(1);
	}
}

