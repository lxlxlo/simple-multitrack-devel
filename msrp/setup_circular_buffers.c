#include "msrp.h"

void setup_circular_buffers() {
	int i;
	extern float *rec_circ_buf[], *play_circ_buf[];
	for (i = 0; i < NUMBUFS; i++) {
		rec_circ_buf[i] = malloc(BUFELEMS * sizeof(float));
		if (rec_circ_buf[i] == NULL) { perror("malloc in main"); exit(1); }
		play_circ_buf[i] = malloc(BUFELEMS * sizeof(float));
		if (play_circ_buf[i] == NULL) { perror("malloc in main"); exit(1); }
	}
}
