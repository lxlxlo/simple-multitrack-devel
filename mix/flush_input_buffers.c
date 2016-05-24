#include "mix.h"

void flush_input_buffers(struct icstruct *ins, int channels) {
	/* ---------------------------------- */
	/* We just mark the buffer as invalid. */ 
	/* ---------------------------------- */
	int chan;
	for (chan = 0; chan < channels; chan++) {
		ins[chan].validbytes = 0;
	}
}	

