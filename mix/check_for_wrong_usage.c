#include "mix.h"

void check_for_wrong_usage(int argc, char **argv, int *nocs) {
	if (argc < 2) {
		fprintf(stderr, "Usage: mix chans master_gain l_gain r_gain file ...\n");
		exit(1);
	}
	*nocs = atoi(argv[1]);   /* number of chans in output stream*/
	if (*nocs > MAX_OUT_CHANS) {
		fprintf(stderr, "too many output channels\n");
		exit(1);
	} 
	/* args after master_gain and nocs must come in (nocs+1)-tuples. */
	if ((0 != (argc-3) % (*nocs+1)))  {
		fprintf(stderr, "Usage: mix master_gain [g1a g1b file1] ....\n");
		exit(1);
	}
}

