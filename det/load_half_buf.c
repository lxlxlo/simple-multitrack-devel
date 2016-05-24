#include "det.h"

int load_half_buf(short *buf, int which_half, int *bcnt) {
	int bytesread;
	char *ptr;
	ptr = (char *) buf;
	ptr +=  (which_half * HALFBUFBYTES);
	bytesread = read_from_fd(STDIN_FILENO, ptr, HALFBUFBYTES);
	*bcnt += HALFBUFBYTES;
	return bytesread;
}		

