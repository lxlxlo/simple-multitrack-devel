#include "msrp.h"
int fds[2], i, qsize=0, scnt=0;
float *rec_circ_buf[NUMBUFS], *play_circ_buf[NUMBUFS];
int main(int argc, char **argv) {
	int fillreq, b;
	float mkr_time;
	process_args(argc, argv, &mkr_time);
	setup_pipe();	
	setup_device();
	setup_callback();
	setup_circular_buffers();
	skip_some_input_data();
	preload_play_buffers(mkr_time);
	start_device();
	while(1) {
		wait_for_request(&fillreq);
		copy_stdin_to_play_buf(fillreq, mkr_time);
		copy_rec_buf_to_stdout(fillreq);
		qsize--;
	}
	return 0;
}

