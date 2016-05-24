#include "mix.h"
	
void allocate_summing_buf(int **summing_buf, int nocs) {
	if (NULL == (*summing_buf = malloc(INBUFELEMS * sizeof(int) * nocs))) {
		perror("malloc for summing_buf");
		exit(1);
	}
}
	

