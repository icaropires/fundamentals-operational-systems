#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INTEGER_SCANCODES_FILE "../../io/integer_scancodes_file" // File after
																 // to int translation
																 
unsigned char *read_file(char* file_path, int *size){
	FILE *file = fopen(file_path, "r");
	assert(file);

	unsigned char *keys = (unsigned char *) malloc(sizeof(unsigned char));

	int count = 0;
	int keys_size = 1;

	unsigned char key;
	while(fscanf(file, "%c", &key) == 1) {
		if(count >= keys_size){
			keys_size *= 2;	
		}

		unsigned char *aux = (unsigned char *) realloc(keys, keys_size);

		if(!aux){
			fprintf(stderr, "Wasn't possible to allocate enough memory");
			exit(1);
		}
		keys = aux;

		keys[count] = key;
		++count;
	}
	fclose(file);

	*size = count;
	return keys;
}

void write_to_file(char *file_path, unsigned char *keys, int size){
	FILE *file = fopen(file_path, "w");

	for(int i = 0; i <= size; ++i){
		fprintf(file, "%d ", keys[i]);
	}

	fclose(file);
}

int main(int argc, char **argv){
	int size = -1;

	unsigned char *keys = read_file(argv[1], &size);
	write_to_file(INTEGER_SCANCODES_FILE, keys, size);

	free(keys);
	return 0;
}
