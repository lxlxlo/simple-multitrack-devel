#include "mix.h"

void skip_by_reading(int fd) {
	unsigned int b, to_eat;
	char toilet[512]; 

	to_eat = BYTES_PER_MONO_SAMP * get_skipsamps();

	/* If possible, get rid of full toilets full of data. */
	/* Then dispose of the remaining data. */
	while (to_eat > 0) {
		if (to_eat >= sizeof(toilet)) {
			if ((b = read(fd, &toilet, sizeof(toilet))) < 1 ) {
				perror("big read in skip failed");
				exit(1);
			}
			to_eat -= b;	
		}
		if (to_eat < sizeof(toilet)) {
			if ((b = read(fd, &toilet, to_eat)) < 1 ) { 
				perror("little read in skip failed");
				exit(1);
			}
			to_eat -= b;	
		}
	}
}

