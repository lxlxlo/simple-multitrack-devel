#include "msrp.h"

void preload_play_buffers(float mkr_time) {
	int b;
	for (b = 0; b < NUMBUFS; b++) {
		copy_stdin_to_play_buf(b, mkr_time);
	}
}
