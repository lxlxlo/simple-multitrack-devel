#include "lsrp.h"

void get_output_info(struct soundcard *card) {
	struct audio_buf_info info;
	if (ioctl(card->audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1) {
		perror("SNDCTL_DSP_GETOSPACE");
		exit(1);
	}
	card->fragments  = info.fragments;
	card->fragstotal = info.fragstotal;
	card->fragsize   = info.fragsize;
	card->bytes      = info.bytes;
}

