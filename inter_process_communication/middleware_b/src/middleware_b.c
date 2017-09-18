#include "middleware_b.h"
#include "../../utils/utils.c"

int sending_message(int msqid, Message *msg, int flag) {
    assert(msg != NULL);

    if(msgsnd(msqid, msg, sizeof(Message), flag) != -1) {
		return 0;
    } else {
        perror("Error while sending message");
		exit(1);
    }
}

char* attach_sh_memory_segment(int segment_id, void* address){
    char* shared_memory = (char*) shmat(segment_id, address, 0);
    assert(shared_memory != NULL);

    return shared_memory;
}

char* get_msg_from_sh_memory(){

	// Read address from file
    FILE* fp = fopen("../address", "r");
	assert(fp != NULL);

	void* address;
	int segment_id = -5;

    fscanf(fp, "%d %p", &segment_id, &address);
    fclose(fp);

	remove("../address");

	assert(address != NULL);
	assert(segment_id != -5);

	fprintf(stdout, "Got address for shared memory area\n");

	char* shared_memory = attach_sh_memory_segment(segment_id, address);

	assert(shared_memory != NULL);

	return shared_memory;
}

void close_sh_memory(int segment_id, char* shared_memory){
    shmdt(shared_memory);
    shmctl(segment_id, IPC_RMID, 0);
}
