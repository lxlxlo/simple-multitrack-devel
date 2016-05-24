#include "lsrp.h"

void allocate_soundcard_struct(struct soundcard **card_ptr) {
	if ((*card_ptr = malloc(sizeof(struct soundcard))) == NULL) {
		perror("malloc for card struct");
		exit(1);
	}
}

