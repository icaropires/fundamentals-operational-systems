#include "middleware_b.h"

char* attach_sh_memory_segment(int segment_id, void* address){
    char* shared_memory = (char*) shmat(segment_id, address, 0);
    assert(shared_memory != NULL);

    return shared_memory;
}

void fill_info(int *pid, int *segment_id, void **address){
    FILE* file = fopen("../address", "r");
	assert(file != NULL);

	*segment_id = -5;

    fscanf(file, "%d|%d|%p", pid, segment_id, address);
    fclose(file);

	assert(address != NULL);
	assert(*segment_id != -5);

	fprintf(stdout, "Got address for shared memory area\n");
}

char* get_msg_from_sh_memory(){
	void* address;
	int pid, segment_id;
	
	fill_info(&pid, &segment_id, &address);
	char* shared_memory = attach_sh_memory_segment(segment_id, address);

	assert(shared_memory != NULL);
	return shared_memory;
}

void close_sh_memory(){
	void* address;
	int pid, segment_id;

	fill_info(&pid, &segment_id, &address);
	char* shared_memory = attach_sh_memory_segment(segment_id, address);

	assert(shared_memory != NULL);

    shmdt(shared_memory);
    shmctl(segment_id, IPC_RMID, 0);

	remove("../address");
}
