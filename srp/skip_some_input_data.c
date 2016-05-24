#include "srp.h"

void skip_some_input_data(void) {
	extern int scnt;
	int skipsamps;
	
	skipsamps = get_skipsamps();
	
	/* The samplecount, scnt, gets advanced by skipsamps to take into
	   account the input data that this program will never see since it
	   is being skipped over.  */
	scnt += skipsamps;
}

