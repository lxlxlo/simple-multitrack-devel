/*  det.c

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

/* Copyright 2004 Kurt Rosenfeld */

#include "det.h"

/* The times that this programs reports are not correct. */

int main(void) {
	short buf[BUFELEMS];
	int past_base, pres_base, winbase, i, bcnt = 0, maxlevel, bytesread;
	int pres_half; /* 0 for first half, 1 for second half */	
	int e_now, e_ago, v_now, v_ago; /* ago is HALFBUF ago */
	skip_some_input_data(&bcnt);	
	bytesread = load_half_buf(buf, 0, &bcnt);
	pres_half=1;	

	/* If we hit EOF on the last read call, we stop. */
	while (bytesread == HALFBUFBYTES) {
		bytesread = load_half_buf(buf, pres_half, &bcnt); 
		maxlevel=0;
		past_base = pres_half ? 0 : HALFBUFELEMS;
		pres_base = pres_half ? HALFBUFELEMS : 0;
		for (winbase=e_ago=e_now=0; winbase < HALFBUFELEMS; winbase += WINELEMS) {	
			for (i = 0; i < WINELEMS; i++) {
				v_ago = abs(buf[past_base + winbase + i]);
				v_now = abs(buf[pres_base + winbase + i]);
				e_ago += v_ago;
				e_now += v_now;
				if (v_now > maxlevel) maxlevel = v_now; 
			}
			if (detect_marker(e_now, e_ago)) {
				report_marker(bcnt, winbase);
				break;
			}
		}
		report_level(maxlevel, bcnt);	
		pres_half = pres_half ? 0 : 1; /* toggle */	
	}
	return 0;
}
