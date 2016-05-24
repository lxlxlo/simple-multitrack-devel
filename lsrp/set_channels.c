#include "lsrp.h"

void set_channels(struct soundcard *card) {
	if (ioctl(card->audio_fd,SNDCTL_DSP_CHANNELS,&(card->channels))== -1) {
    		perror("SNDCTL_DSP_CHANNELS"); 
		exit(1);
	}

	if (card->channels != 2) { 
		perror("The device doesn't support stereo mode");
		exit(1);
	}
}

