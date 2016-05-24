#include "msrp.h"

OSStatus callback(AudioDeviceID inDevice, 
			const AudioTimeStamp * inNow,
			const AudioBufferList * inInputData,
			const AudioTimeStamp * inInputTime,
			AudioBufferList * outOutputData,
			const AudioTimeStamp * outOutputTime, 
			void * inClientData) {
	extern int fds[2], qsize;
	extern float *rec_circ_buf[], *play_circ_buf[];
	static int err=0, actbuf=0;
	int i;
	float *d;
	/* ----- make gcc happy -------- */
	UInt32 foo = inDevice + inNow->mFlags + inInputTime->mFlags;
	foo += outOutputTime->mFlags + (int) inClientData;
	/* ----------------------------- */
	if (qsize > 20) {
		fprintf(stderr, "(%d) qsize=%d\n", err, qsize);
		err++;
	}
	d = outOutputData->mBuffers[0].mData;
	for (i=0; i<1024; i++) {
		d[i] = play_circ_buf[actbuf][i];
	}
	d = inInputData->mBuffers[0].mData;
	for (i=0; i<1024; i++) {
		rec_circ_buf[actbuf][i] = d[i];
	}
	qsize++;
	write(fds[1], &actbuf, sizeof(actbuf)); 
	actbuf = (actbuf + 1) % NUMBUFS;
  return kAudioHardwareNoError;
}

