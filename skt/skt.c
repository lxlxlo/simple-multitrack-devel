#include "skt.h"

int main(int argc, char **argv) {
	int file_fd, bytesread=BUFBYTES;
	char buf[BUFBYTES];

	process_args(argc, argv, &file_fd);
	if (argc == 2) skip_by_seeking(file_fd);
	
	while (bytesread == BUFBYTES) {
		bytesread = read_from_fd(STDIN_FILENO, buf, BUFBYTES);
		write_to_fd(STDOUT_FILENO, buf, bytesread);
		if (argc == 2) write_to_fd(file_fd, buf, bytesread);
	}
	return 0;
}
