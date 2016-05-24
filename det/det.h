
#ifndef _DET_H
#define _DET_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "../common/common.h"


#define BUFELEMS 44100 
#define BUFBYTES 88200 
#define HALFBUFELEMS 22050
#define HALFBUFBYTES 44100 
#define WINELEMS 441
#define WINBYTES 882
#define NUMWINS 50

#define BYTES_PER_SECOND 88200
#define SHORTBYTES 2
#define DET_THRESHOLD 5 

int load_half_buf(short * buf, int which_half, int *bcnt); 
int detect_marker(int e_now, int e_before); 
void report_marker(int bcnt, int winbase); 
void report_level(int max_level, int bcnt); 
void skip_some_input_data(int *); 
int get_skipsamps(void); 

#endif /* !_DET_H */
