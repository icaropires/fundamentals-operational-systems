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

void fill_info(int *segment_id, void **address){
    FILE* file = fopen(TMP_FILE, "r");
	assert(file != NULL);

	*segment_id = -5;

    if(fscanf(file, "%d|%p", segment_id, address) < 3){
		fprintf(stderr, "There was a problem reading the file");
	}

	assert(address != NULL);
	assert(*segment_id >= 0);

	fprintf(stderr, "Got address for shared memory area\n");
    fclose(file);
}

void binary_semaphore_wait(int semid) {
    struct sembuf operations[1];

    operations[0].sem_num = 0;
    operations[0].sem_op = -1;
    operations[0].sem_flg = SEM_UNDO;

    if(semop(semid, operations, 1)){
       perror("Wasn't possible to down on semaphore");
    }
}
