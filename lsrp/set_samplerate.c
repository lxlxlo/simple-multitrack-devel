#include "lsrp.h"

void set_samplerate(struct soundcard *card) {
	if (ioctl(card->audio_fd, SNDCTL_DSP_SPEED, &(card->speed)) == -1) {
		perror("SNDCTL_DSP_SPEED"); 
		exit(1);
	}

	if (abs(card->speed - DESIRED_SAMPLE_RATE) > SAMPLE_RATE_TOL) {
		fprintf(stderr, "can't do %d samp/sec\n", DESIRED_SAMPLE_RATE);
		exit(1);
	}
}

