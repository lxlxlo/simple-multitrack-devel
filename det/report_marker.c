#include "det.h"

void report_marker(int bcnt, int winbase) {
		int markerbyte;
		char dashes[]="------------------------------\0";
		float markertime;
		markerbyte = 	bcnt - HALFBUFBYTES;    /* beginning of this halfbuf */ 
		markerbyte += winbase * SHORTBYTES; /* beginning of this window */
		markerbyte += WINBYTES / 2; 				/* center of this window */
		markertime = 	(float) markerbyte / BYTES_PER_SECOND;
		fprintf(stderr, "%s%s marker: %.3f sec\n", dashes, dashes, markertime);
}
