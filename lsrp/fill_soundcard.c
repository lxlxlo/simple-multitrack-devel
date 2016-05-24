#include "lsrp.h"

void fill_soundcard(struct soundcard *card, char *frag, int fragsize, float mkr_time) {
	int fragcount, i, bytesread;
	for (fragcount=0; fragcount < card->fragstotal; fragcount++) {
		for (i=0; i < fragsize; i+=bytesread) {
			bytesread = read(0, frag+i, fragsize-i); 
			if (bytesread < 1) {
				perror("fill_soundcard read(stdin) failed");
				exit(1);
			}
		}
		add_marker(frag, fragsize, mkr_time);
		if (write (card->audio_fd, frag, fragsize) != fragsize) {
			perror("fill_soundcard");
			exit(1);
		}
	}
}
	
