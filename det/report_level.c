#include "det.h"

void report_level(int maxlevel, int bcnt) {
	float ttime = (float) bcnt / BYTES_PER_SECOND;
	char msgbuf[256];
	int i;
	for (i=0; i<=32; i++) {
		if (maxlevel > i*1000) msgbuf[i] = '*';
		else msgbuf[i] = ' ';
	}	
	msgbuf[i]=0;
	if (maxlevel > SHRT_MAX - 1) {
		fprintf(stderr, "%s| %5d OVERLOAD %.3f sec\n", msgbuf, maxlevel, ttime);
	}
	else {
		fprintf(stderr, "%s| %5d          %.3f sec\n", msgbuf, maxlevel, ttime);
	}
}
