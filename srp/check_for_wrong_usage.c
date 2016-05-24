#include "srp.h"

void check_for_wrong_usage(int argc) {
	if (argc > 2) {
		fprintf(stderr, "Usage: srp [marker_time]\n");
		exit(1);
	}
}

