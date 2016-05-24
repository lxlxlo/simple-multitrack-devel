/* COPYRIGHT 2004 Kurt Rosenfeld */

#ifndef _MIX_H
#define _MIX_H

#define INBUFELEMS 256 /* 512 bytes = 256 mono 16-bit samples */
#define INBUFBYTES 512 /* 512 bytes = 256 mono 16-bit samples */

#define MAX_OUT_CHANS 8 /* a stream of 8 interleaved channels  */
#define MAX_INPUTS 100
#define FULL 0
#define NOTFULL 1
#define MAXGAIN 100
#define CLIPPING_POINT 32767

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "../common/common.h"

struct icstruct {
	int fd, validbytes;
	double gain[MAX_OUT_CHANS];
	short buf[INBUFELEMS];
};

void check_for_wrong_usage(int, char **, int *); 
void process_args(int, char **, struct icstruct *, int *, int *);
void fill_input_buffers(struct icstruct *, int); 
void mix_channels(struct icstruct *, int, int *, int);
void fill_output_buffer(int *, short *, int); 
void write_output(short *, int nocs); 
void flush_input_buffers(struct icstruct *, int);	
void clean_up(struct icstruct *, int);
void spawn_and_setup_pipe(char *, int *);
void allocate_summing_buf(int **, int); 
void allocate_outbuf(short **, int, int *); 
int buffer_status(struct icstruct *, int); 
void skip_by_reading(int); 
int filename_ends_in_mix(char *);

#endif /* !_MIX_H */
