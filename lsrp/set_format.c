
#include "lsrp.h"

void set_format(struct soundcard *card) {
	if (ioctl(card->audio_fd, SNDCTL_DSP_SETFMT, &(card->format)) == -1) {
		perror("SNDCTL_DSP_SETFMT"); 
		exit(1);
	}

	if (card->format != AFMT_S16_NE) {
		perror("Can't do AFMT_S16_NE");
		exit(1);
	}
}

