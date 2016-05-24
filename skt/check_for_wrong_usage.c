#include "skt.h"

void check_for_wrong_usage(int argc) {
	if (argc > 2) {
		fprintf(stderr, "Usage: skt [filename]\n");
		exit(1);
	}
}

