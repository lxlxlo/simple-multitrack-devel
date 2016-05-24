# This makefile should not exist as such.  There should be a configure script.

CC =  gcc
FLAGS = -O2 -W -Wall -Wstrict-prototypes 

OBJS = 	wait_for_request.o \
	../common/write_to_fd.o \
	../common/pad.o \
	../common/read_from_fd.o \
	../common/get_skipsamps.o \
	../srp/make_mono.o \
	../srp/process_args.o \
	../srp/check_for_wrong_usage.o \
	../srp/add_marker.o \
	../srp/skip_some_input_data.o \
	copy_stdin_to_play_buf.o \
	copy_rec_buf_to_stdout.o \
	setup_circular_buffers.o \
	preload_play_buffers.o \
	setup_pipe.o \
	setup_callback.o \
	cleanup.o \
	start_device.o \
	callback.o \
	setup_device.o \
	msrp.o

msrp : $(OBJS) 
	$(CC) $(CFLAGS) -framework CoreAudio -o $@ $(OBJS) 

clean :  
	rm -f *.o msrp

$(OBJS) : msrp.h

