#include "srp.h"
#define MAX_MARKER 3600

void process_args(int argc, char **argv, float *marker_time) {
	*marker_time = -1;

	check_for_wrong_usage(argc);

	if (argc > 1) {
		*marker_time	= atof(argv[1]);   

		if (*marker_time < 0) {
			fprintf(stderr, "marker_time cannot be negative\n");
			exit(1);
		}

		if (*marker_time > MAX_MARKER) {
			fprintf(stderr, "the marker you request (in seconds) is really late\n");
		}
	}
}
