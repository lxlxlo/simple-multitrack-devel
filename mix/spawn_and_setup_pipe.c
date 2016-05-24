#include "mix.h"

void spawn_and_setup_pipe(char *filename, int *parent_fd) {
	/* -------------------------------------- */
	/* We will fork() and exec() the file and */
	/* get a file descriptor for the end of a */
	/* half-duplex pipe from which the parent */
	/* reads.  The fd, which is passed by to  */
	/* this function by reference is really a */
	/* member of ins[chan] just like the fd   */
	/* obtained when plain files are opened.  */
	/* -------------------------------------- */

	int fd[2], child_pid;
	fprintf(stderr, "file \"%s\" is executable, ", filename);
	fprintf(stderr, "running it as a generator.\n");
	if (-1 == pipe(fd)) {
		fprintf(stderr, "pipe() failed\n");
		exit(1);
	}
	if ((child_pid = fork()) == 0) { /* we are the child */
		if (-1 == close(fd[0])) { /* we won't read from parent */
			fprintf(stderr, "close() failed in child\n");
			exit(1);
    }
		if (-1 == close(1)) {  /* we close stdout and use the fd for pipe */
			fprintf(stderr, "close(1) failed in child\n");
			exit(1);
		}
        
		if (-1 == dup(fd[1])) {  /* it dups to stdout since stdout is closed*/
			fprintf(stderr, "dup() failed\n");
			exit(1);
		}
		execlp(filename, filename, NULL);
		fprintf(stderr, "execlp() returned.  That is bad. \n");
		exit(1);
	}
	if (-1 == child_pid) {
  	fprintf(stderr, "fork() failed\n");
   	exit(1);
	}
	else {   /* we are the parent */
		if (-1 == close(fd[1])) {
			fprintf(stderr, "close() failed on parent end of pipe\n");
			exit(1);
		}
		*parent_fd = fd[0];
  }
}

