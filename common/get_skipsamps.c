#include "common.h"

int get_skipsamps(void) {
	char varname[]="skipsamps";
	char *skipsamps_env;
	int skipsamps = 0;

	if (NULL != (skipsamps_env = getenv(varname))) {
		skipsamps = atoi(skipsamps_env);
	}
	
	if (skipsamps < 0) {
		fprintf(stderr, "mix %s value can't be negative\n", varname);
		exit(1);
	}

	return skipsamps;
}
