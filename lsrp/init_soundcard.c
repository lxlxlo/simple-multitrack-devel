
#include "lsrp.h"

void init_soundcard(struct soundcard *card) {
	card->channels = 2; 
	card->speed = DESIRED_SAMPLE_RATE;
	card->format = AFMT_S16_NE; 

	open_soundcard(card);
	set_full_duplex(card);
	get_capabilities(card);
	set_format(card);
	set_channels(card);
	set_samplerate(card);
}

