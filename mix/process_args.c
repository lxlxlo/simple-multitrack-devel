#include "mix.h"

void process_args(int argc, char **argv, 
									struct icstruct *ins, int *channels, int *nocs) {
  struct stat *mystat; /* see STAT HACK in the README file */
	int argidx = 2; /* argument index skips invocation name and nocs*/ 
	int chan = 0; /* chan is which input channel we are dealing with */
	double mgain; /* master gain that scales all outputs*/
	int c; /* c indexes through the output levels for each input  */

	mgain = atof(argv[argidx++]);   
	if (NULL == (mystat = malloc(sizeof(struct stat)))) {
		fprintf(stderr, "malloc() failed for stat struct in process_args()\n");
		exit(1);
	}

	while (argidx < argc) {
		for (c = 0; c < *nocs; c++) {
			ins[chan].gain[c] = atof(argv[argidx++]) * mgain;  
		}
		
		if (-1 == stat(argv[argidx], mystat)) { 
			fprintf(stderr, "couldn't stat() %s\n", argv[argidx]);
			exit(1);
		}

		if (mystat->st_mode & S_IXUSR) { /* file is executable, run it */
			spawn_and_setup_pipe(argv[argidx], &ins[chan].fd);

			if (! filename_ends_in_mix(argv[argidx++])) { 
				fprintf(stderr, "filename does not end in mix\n");
				skip_by_reading(ins[chan].fd);
			}
			else {
			fprintf(stderr, "filename ends in mix\n");
			}
			
		}

		else { /* file is not executable */
			ins[chan].fd = open(argv[argidx++], O_NONBLOCK); 
			if (-1 == ins[chan].fd) {   /* open() failed */
				fprintf(stderr,"Can't open file: %s\n",argv[argidx-1]);
				exit(1);
			}	
			skip_by_seeking(ins[chan].fd);
		}
		ins[chan].validbytes=0;
		chan++;	
	}
	*channels = chan;
}

