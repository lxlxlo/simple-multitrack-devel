#include "lsrp.h"

void activate_soundcard(struct soundcard *card) {
	int enable_bits;
	enable_bits = PCM_ENABLE_INPUT | PCM_ENABLE_OUTPUT;
	if (ioctl(card->audio_fd, SNDCTL_DSP_SETTRIGGER, &enable_bits) == -1) {
		perror("SNDCTL_DSP_SETTRIGGER");
		exit(1);
	}
}

