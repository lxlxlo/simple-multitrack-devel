#include "mix.h"

int filename_ends_in_mix(char *filename) {
	size_t i;
	i = strlen(filename);
	if (i < 3) return 0;
	if (filename[--i] != 'x') return 0;
	if (filename[--i] != 'i') return 0;
	if (filename[--i] != 'm') return 0;
	return 1;
}
