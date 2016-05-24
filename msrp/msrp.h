#ifndef __MSRP_H__
#define __MSRP_H__

//#include <errno.h>
#include <CoreAudio/CoreAudio.h>
#include "../common/common.h"
#include "../srp/srp.h"

#define NUMBUFS 200
#define BUFELEMS 1024

AudioDeviceID audiodev;   

void setup_device(void);
void setup_callback(void);
void setup_circ_buf(void);
void preload_play_buffers(float mkr_time);
void copy_stdin_to_play_buf(int which_buf, float mkr_time);
void copy_rec_buf_to_stdout(int which_buf);
void wait_for_request(int *fillreq);
void setup_pipe(); 
void start_device(void);

OSStatus callback(AudioDeviceID inDevice, 
				const AudioTimeStamp * inNow,
				const AudioBufferList * inInputData,
				const AudioTimeStamp * inInputTime,
				AudioBufferList * outOutputData,
				const AudioTimeStamp * outOutputTime, 
				void * inClientData);
#endif /* __MSRP_H__ */
