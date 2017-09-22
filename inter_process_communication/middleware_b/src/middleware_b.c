#include "middleware_b.h"

int SEMID;

char* get_msg_from_sh(int segment_id, void** address){
    char* shared_memory = (char*) shmat(segment_id, *address, 0);

	// Make sure memmory was allocated
	if(shared_memory == (char *) -1){
		perror("Wasn't possible allocate shared memory");
	}

    // shmdt(shared_memory);
    // shmctl(segment_id, IPC_RMID, 0);

    return shared_memory;
}

void fill_info(int *segment_id, void **address){
    FILE* file = fopen(TMP_FILE, "r");
	assert(file != NULL);

	*segment_id = -5;

    if(fscanf(file, "%d|%p", segment_id, address) < 2){
		fprintf(stderr, "There was a problem reading the file\n");
	}

	assert(address != NULL);
	assert(*segment_id >= 0);

	fprintf(stderr, "Got address for shared memory area\n");
    fclose(file);
}

