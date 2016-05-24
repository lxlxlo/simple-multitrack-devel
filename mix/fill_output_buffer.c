
#include "mix.h"

void fill_output_buffer(int *summing_buf, short *outbuf, int nocs) {
	/* -------------------------------------------------------------- */
	/* Before we convert from ints to shorts, we check for clipping.  */
	/* -------------------------------------------------------------- */
	int i;
	for (i=0; i < INBUFELEMS * nocs; i+=2) {
		if (abs(summing_buf[i]) >= CLIPPING_POINT) {
			fprintf(stderr, "clipping left  in 32 -> 16-bit %d\n",
				summing_buf[i]);
		}
		if (abs(summing_buf[i+1]) >= CLIPPING_POINT) {
			fprintf(stderr, "clipping right in 32 -> 16-bit %d\n",
				summing_buf[i+1]);
		}
		outbuf[i] =   (short) (summing_buf[i]);
		outbuf[i+1] = (short) (summing_buf[i+1]);
	}
}

