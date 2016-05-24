#ifndef _SRP_H
#define _SRP_H

#include "../common/common.h"

#define DESIRED_SAMPLE_RATE 44100

void make_mono(char *, int);
void skip_some_input_data(void);
void check_for_wrong_usage(int);
void process_args(int, char **, float *);
void add_marker(char *, int, float);

#endif /* !_SRP_H */
