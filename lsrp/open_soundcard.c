#include "lsrp.h"

void open_soundcard(struct soundcard *card) {
	if ((card->audio_fd = open(DEVICE_NAME, O_RDWR, 0)) == -1) {
		perror(DEVICE_NAME); 
		exit(1);
	}
}

