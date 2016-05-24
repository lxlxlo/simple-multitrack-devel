
#include "lsrp.h"

int scnt=0;
int main (int argc, char **argv) {
	int fragsize, monofragsize;
	float mkr_time;
	char *frag;
	struct soundcard *card;
	process_args(argc, argv, &mkr_time);
	allocate_soundcard_struct(&card);
	init_soundcard(card); 
	get_input_info(card);
	get_output_info(card);
	fragsize = card->fragsize; 
	monofragsize = fragsize / 2;
	allocate_frag_buffer(&frag, fragsize);
	skip_some_input_data();
	freeze_soundcard(card); 
	fill_soundcard(card, frag, fragsize, mkr_time);
	empty_input_buffer(card);  
	activate_soundcard(card);

	while (read_from_fd(STDIN_FILENO, frag, fragsize)) {
		add_marker(frag, fragsize, mkr_time);
		write_to_fd (card->audio_fd, frag, fragsize);
		read_from_fd(card->audio_fd, frag, fragsize);
		make_mono(frag, fragsize); 
		write_to_fd(STDOUT_FILENO, frag, monofragsize); 
	}

	clean_up(card, frag);
	return 0;
}

