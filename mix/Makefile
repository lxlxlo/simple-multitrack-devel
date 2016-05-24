# This makefile should not exist as such.  There should be a configure script.

CC =  gcc
CFLAGS = -O2 -W -Wall -Wstrict-prototypes 
OBJS = allocate_outbuf.o allocate_summing_buf.o check_for_wrong_usage.o clean_up.o fill_input_buffers.o fill_output_buffer.o flush_input_buffers.o mix.o mix_channels.o ../common/pad.o process_args.o spawn_and_setup_pipe.o ../common/write_to_fd.o ../common/skip_by_seeking.o skip_by_reading.o ../common/get_skipsamps.o filename_ends_in_mix.o ../common/read_from_fd.o

mix : $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS) 

clean :  
	rm -f *.o mix 

$(OBJS) :  

