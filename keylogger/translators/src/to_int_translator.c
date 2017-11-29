#include "functions.h"

int main(int argc, char **argv){
	int size = -1;

	unsigned char *keys = read_file(argv[1], &size);
	write_to_file(INTEGER_SCANCODES_FILE, keys, size);

	free(keys);
	return 0;
}
