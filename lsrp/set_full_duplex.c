#include "lsrp.h"

void set_full_duplex(struct soundcard *card) {
	if (ioctl(card->audio_fd, SNDCTL_DSP_SETDUPLEX, 0) == -1) {
		perror("SNDCTL_DSP_SETDUPLEX");
		exit(1);
	}
}
	
