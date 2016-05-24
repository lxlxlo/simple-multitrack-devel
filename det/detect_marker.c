#include "det.h"

int detect_marker(int e_now, int e_before) {
	if (e_now > (DET_THRESHOLD * e_before)) return 1;
	else return 0;
}
