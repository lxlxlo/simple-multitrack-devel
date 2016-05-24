#include "skt.h"
#define FILEARG 1

void process_args(int argc, char **argv, int *fd) {
	
	check_for_wrong_usage(argc);

	if (argc == 2) {
		*fd = creat(argv[FILEARG], S_IREAD|S_IWRITE); 
		if (-1 == *fd) {   /* open() failed */
			perror("skt");
			exit(1);
		}	
	}
}

