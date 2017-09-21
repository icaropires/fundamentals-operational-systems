#include "middleware_b.h"

void get_msg_from_sh(int segment_id, void** address, char** ptr_msg){
    char* shared_memory = (char*) shmat(segment_id, *address, 0);

	// Make sure memmory was allocated
	if(shared_memory == (char *) -1){
		perror("Wasn't possible allocate shared memory");
	}

	*ptr_msg = malloc(MESSAGE_SIZE);
	strcpy(*ptr_msg, shared_memory);

    shmdt(shared_memory);
    shmctl(segment_id, IPC_RMID, 0);
}

void fill_info(pid_t host_b_pid, pid_t *host_a_pid, int *segment_id, void **address){
    FILE* file = fopen(TMP_FILE, "r");
	assert(file != NULL);

	*segment_id = -5;

    if(fscanf(file, "%d|%d|%p", (int*)host_a_pid, segment_id, address) < 3){
		fprintf(stderr, "There was a problem reading the file");
	}

	assert(address != NULL);
	assert(*segment_id >= 0);

	fprintf(stderr, "Got address for shared memory area\n");
    fclose(file);

    FILE * fle = fopen(TMP_FILE, "w");
    assert(file != NULL);

    fprintf(file, "%d", host_b_pid);

    fclose(file);
    fprintf(stderr, "Wrote host_b pid to file\n");
}
