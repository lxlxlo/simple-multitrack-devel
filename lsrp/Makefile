# This makefile should not exist as such.  There should be a configure script.

CC =  gcc
CFLAGS = -O2 -W -Wall -Wstrict-prototypes 

OBJS =  ../common/pad.o \
	../common/write_to_fd.o \
	../common/read_from_fd.o \
	../common/get_skipsamps.o \
	../srp/make_mono.o \
	../srp/skip_some_input_data.o \
	../srp/check_for_wrong_usage.o \
	../srp/process_args.o \
	../srp/add_marker.o \
	activate_soundcard.o \
	allocate_frag_buffer.o \
	allocate_soundcard_struct.o \
	clean_up.o \
	empty_input_buffer.o \
	fill_soundcard.o \
	freeze_soundcard.o \
	get_capabilities.o \
	get_input_info.o \
	get_output_info.o \
	init_soundcard.o \
	open_soundcard.o \
	set_channels.o \
	set_format.o \
	set_full_duplex.o \
	set_samplerate.o \
	lsrp.o 

lsrp : $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm

clean :  
	rm -f *.o lsrp

$(OBJS) : lsrp.h 

