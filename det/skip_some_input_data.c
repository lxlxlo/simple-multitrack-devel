#include "det.h"
/* Here we are just pretending that we saw skipbytes of input data
   even though we didn't. */
void skip_some_input_data(int *bytecount) {
	*bytecount += get_skipsamps() * SHORTBYTES;
}

