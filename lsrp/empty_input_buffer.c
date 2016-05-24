#include "lsrp.h"

void empty_input_buffer(struct soundcard *card) {
	char *frag;
	int fragsize = card->in_fragsize;
	if ((frag = malloc(fragsize)) == NULL) {  
		fprintf(stderr, "malloc failed in empty_input_buffer\n");
		exit(1);
	}
	while (read (card->audio_fd, frag, fragsize) == fragsize) { }
	free(frag);
}

