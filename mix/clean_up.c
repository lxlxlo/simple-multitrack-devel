#include "mix.h"

void clean_up(struct icstruct *ins, int channels) {
	int chan;
	for (chan = 0; chan < channels; chan++) {
		close(ins[chan].fd);
	}		
}

