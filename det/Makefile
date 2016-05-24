# This makefile should not exist as such.  There should be a configure script.

CC =  gcc
CFLAGS = -O2 -W -Wall -Wstrict-prototypes 
OBJS = load_half_buf.o \
	../common/get_skipsamps.o \
	../common/read_from_fd.o \
	../common/pad.o \
	detect_marker.o \
	report_marker.o \
	report_level.o \
	det.o \
	skip_some_input_data.o \

det : $(OBJS) det.h
	$(CC) $(CFLAGS) -o $@ $(OBJS) 

clean :  
	rm -f *.o det

$(OBJS) : det.h 
