#include "srp.h"

void make_mono(char *frag, int fragsize) {
	/* Convert stereo data to mono (only the left channel) */ 	
	int i;
	for (i=0; i < fragsize/2; i+=2) {
		frag[i] = frag[2*i];
		frag[i+1]=frag[2*i + 1]; 	
	}
}

