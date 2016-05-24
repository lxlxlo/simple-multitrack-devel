# This makefile should not exist as such.  There should be a configure script.

CC =  gcc
CFLAGS = -O2 -W -Wall -Wstrict-prototypes 
OBJS =  ../common/get_skipsamps.o \
	../common/read_from_fd.o \
	../common/pad.o \
	../common/write_to_fd.o \
	../common/skip_by_seeking.o \
	process_args.o \
	check_for_wrong_usage.o \
	skt.o 

skt : $(OBJS) skt.h
	$(CC) $(CFLAGS) -o $@ $(OBJS) 

clean :  
	rm -f *.o skt

$(OBJS) : skt.h 
