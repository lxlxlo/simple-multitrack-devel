#include "msrp.h"
#include <limits.h>
void copy_rec_buf_to_stdout(int whichbuf) {
	int i;
	extern float *rec_circ_buf[];
	short stdout_buf[BUFELEMS];
	float s;
	for (i=0; i<BUFELEMS; i++) {
		s = rec_circ_buf[whichbuf][i];
		s *= SHRT_MAX;
		stdout_buf[i] = (short) s;
	}
	make_mono((char *)stdout_buf, BUFELEMS*sizeof(short));
	write_to_fd(1, (char*)stdout_buf, (BUFELEMS/2)*sizeof(short));
}
