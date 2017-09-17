#include "middleware_a.h"
#include "../../utils/utils.c"

int receiving_message(int msqid, Message *msg, int arb_number, int flag) {
	// Check if there are messages on this queue.
	struct msqid_ds buf;
	if(!msgctl(msqid, IPC_STAT, &buf)){
		fprintf(stdout, "There is no messages on this queue, waiting...\n");
	} else {
		perror("Couldn't check this queue");
		exit(1);
	}

	int bytes = msgrcv(msqid, msg, sizeof(Message), ARB_NUMBER, FLAG);
    if(bytes != -1){
		return bytes;	
	} else {
		perror("Message couldn't be sent");
		exit(1);
	}
}

int allocate_sh_memory(size_t size){
    const int shared_segment_size = sizeof(size);

    int segment_id = shmget(IPC_PRIVATE, shared_segment_size,
                            IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR); 
}

char* attach_sh_memory_segment(int segment_id, size_t expected_size){
    char* shared_memory = (char*) shmat(segment_id, NULL, 0);
    assert(shared_memory != NULL);

    fprintf(stdout, "id: %d\n", segment_id);
    
    // Check the segment’s size.
    struct shmid_ds buf;
    shmctl(segment_id, IPC_STAT, &buf);

    int segment_size = buf.shm_segsz;
    fprintf(stdout, "%d\n", segment_size);
    //assert(segment_size == expected_size);

    return shared_memory;
}

void pass_msg_to_sh_memory(Message msg){
    const int msg_size = sizeof(Message);

    int segment_id = allocate_sh_memory(msg_size);
    char* shared_memory = attach_sh_memory_segment(segment_id, msg_size);
    // sprintf(shared_memory, "OLA");
    strcpy(shared_memory, msg.msg);
}

void close_sh_memory(int segment_id, char* shared_memory){
    shmdt(shared_memory);
    shmctl(segment_id, IPC_RMID, 0);
}
