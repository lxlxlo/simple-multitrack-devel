#include "lsrp.h"

void clean_up(struct soundcard *card, char *frag) {
	free(frag);
	if (0 != close(card->audio_fd)) {
		perror("can't close audio_fd");
		exit(1);
	}
}

