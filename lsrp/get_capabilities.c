#include "lsrp.h"

void get_capabilities(struct soundcard *card) {
	int caps; 
	if (ioctl(card->audio_fd, SNDCTL_DSP_GETCAPS, &caps) == -1) {
		perror("SNDCTL_DSP_GETCAPS");
		exit(1);
	}
	if ((caps & DSP_CAP_DUPLEX) == 0) {
		fprintf(stderr, "The soundcard doesn't support full-duplex.\n");
		exit(1);
	}
	if ((caps & DSP_CAP_TRIGGER) == 0) {
		fprintf(stderr, "The soundcard doesn't support triggering.\n");
		exit(1);
	}
}
	
