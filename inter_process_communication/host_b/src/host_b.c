#include <host_b.h>

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
