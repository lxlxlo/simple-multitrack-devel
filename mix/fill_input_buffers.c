
#include "mix.h"

void fill_input_buffers(struct icstruct *ins, int nics) {
	int chan;
		
	for (chan = 0; chan < nics; chan++) {
		read_from_fd(ins[chan].fd, (char *)ins[chan].buf, INBUFBYTES);
	}
}

