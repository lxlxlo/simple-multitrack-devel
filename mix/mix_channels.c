
#include "mix.h"

void mix_channels(struct icstruct *ins, int channels, int *summing_buf, int nocs) {
	/* -----------------------------------------------------------*/	
	/* Here we copy/convert from chars in the input buf to ints   */
	/* in summing buffer.  We also scale each channel by          */
	/* its gain settings before adding it to the mix.             */
	/* -----------------------------------------------------------*/	
	int i, chan;
	int c; /* 0 for left, 1 for right, maybe more for fancy cards */
	for(i = 0; i < INBUFELEMS * nocs; i++)   { /* Initialize accumulator. */
		summing_buf[i] = 0;
	}

	for (chan = 0; chan < channels; chan++) {
		for (i=0; i < INBUFELEMS; i++) {
			int sample_32;
			short *sample_16_ptr;
			sample_16_ptr = (short *) &ins[chan].buf[i];
			sample_32 = (int) *sample_16_ptr; 
			for (c = 0; c < nocs; c++) {
				summing_buf[nocs * i + c] += sample_32 * ins[chan].gain[c];
			}
		}
	}
}

