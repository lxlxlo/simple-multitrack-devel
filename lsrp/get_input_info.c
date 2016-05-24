#include "lsrp.h"

void get_input_info(struct soundcard *card) {
	struct audio_buf_info info;
	if (ioctl(card->audio_fd,SNDCTL_DSP_GETISPACE, &info) == -1) {
		perror("SNDCTL_DSP_GETSPACE");
		exit(1);
	}
	card->in_fragments  = info.fragments;
	card->in_fragstotal = info.fragstotal;
	card->in_fragsize   = info.fragsize;
	card->in_bytes      = info.bytes;
}
		
