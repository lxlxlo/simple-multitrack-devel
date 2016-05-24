#include "msrp.h" 

void copy_stdin_to_play_buf(int whichbuf, float mkr_time) {
	int i;
	extern float *play_circ_buf[];
	short stdin_buf[BUFELEMS];
	read_from_fd(0, (char*)stdin_buf, BUFELEMS*sizeof(short));
	add_marker((char *)stdin_buf, BUFELEMS*sizeof(short), mkr_time);
	for (i=0; i<BUFELEMS; i++) {
		play_circ_buf[whichbuf][i] = (float)stdin_buf[i]/SHRT_MAX;
	}
}
