#include "srp.h"

/* This code assumes that the audio stream is in native byte order. */
/* Some of this stuff could be calculated once somewhere else and 
   passed in, or done statically. */

void add_marker(char *frag, int fragbytes, float mkr_time) {
	signed short *s=(short *)frag;
	extern int scnt; /* sample count */
	int i, mkr_beg, mkr_end;
	int mkr_len=2000; /* 2000 samples at 44100 samp/sec = 45msec beep duration */
	int mkr_samp; /* number of stereo samples from beginning of track to beep */
	float program_level_during_beep = 0.5; /* these levels should add up to 1 */
	float tone_level_during_beep = 0.5;
	int tone_period = 5; /* number of samples for tone to make one cycle */
	mkr_samp = mkr_time * DESIRED_SAMPLE_RATE;
	mkr_beg = mkr_samp;
	mkr_end = mkr_samp + mkr_len;

	for (i=0; i < fragbytes; i+=BYTES_PER_STEREO_SAMPLE) {
		if ((scnt >= mkr_beg) && (scnt < mkr_end)) {
			s = (short *) (frag + i);
			*s *= program_level_during_beep;
			*s += tone_level_during_beep * SHRT_MAX * sin(scnt / tone_period);	
		}
		scnt++;
	}
}
