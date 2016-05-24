#ifndef _LSRP_H
#define _LSRP_H

#include <sys/soundcard.h>
#include "../common/common.h"
#include "../srp/srp.h"

#define DEVICE_NAME "/dev/dsp"
#define SAMPLE_RATE_TOL 10

struct soundcard {
        int audio_fd;
        int channels;
        int speed;
        int format;
	int fragments;
	int fragstotal;
	int fragsize;
	int bytes;
	int in_fragments;
	int in_fragstotal;
	int in_fragsize;
	int in_bytes;
};

void init_soundcard(struct soundcard *);
void open_soundcard(struct soundcard *);
void set_format(struct soundcard *);
void set_channels(struct soundcard *);
void set_samplerate(struct soundcard *);
void get_inputinfo(struct soundcard *);
void get_output_info(struct soundcard *);
void get_input_info(struct soundcard *);
void freeze_soundcard(struct soundcard *);
void fill_soundcard(struct soundcard *, char *, int, float mkr_time);
void activate_soundcard(struct soundcard *);
void clean_up(struct soundcard *, char *frag);
void set_full_duplex(struct soundcard *);
void get_capabilities(struct soundcard *);
void empty_input_buffer(struct soundcard *);
void allocate_soundcard_struct(struct soundcard **);
void allocate_frag_buffer(char **, int fragsize);

#endif /* !_SRP_H */
