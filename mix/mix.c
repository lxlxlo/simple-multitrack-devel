/*  mix.c

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* COPYRIGHT 2004 Kurt Rosenfeld */

#include "mix.h"

int main(int argc, char **argv) {
	struct icstruct ins[MAX_INPUTS];
	short *outbuf;
	int *summing_buf, outbufbytes; 
	int nics; /* number of input channels */
	int nocs; /* number of channels in output stream */

	check_for_wrong_usage(argc, argv, &nocs);
	process_args(argc, argv, ins, &nics, &nocs);
	allocate_summing_buf(&summing_buf, nocs);
	allocate_outbuf(&outbuf, nocs, &outbufbytes);

	while(1) {
		fill_input_buffers(ins, nics);
		mix_channels(ins, nics, summing_buf, nocs);
		fill_output_buffer(summing_buf, outbuf, nocs);
		write_to_fd(1, (char *)outbuf, outbufbytes);
	}

	clean_up(ins, nics);
	return 0;
}


