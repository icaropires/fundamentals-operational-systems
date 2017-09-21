#include "middleware_a.h"

int allocate_sh_memory(size_t size){
    const int shared_segment_size = sizeof(size);

    const int segment_id = shmget(IPC_PRIVATE, shared_segment_size,
                            IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR); 

	return segment_id;
}

char* attach_sh_memory_segment(int segment_id, size_t expected_size){
    char* shared_memory = (char*) shmat(segment_id, NULL, 0);
    assert(shared_memory != NULL);

	return shared_memory;
}

void write_info(int segment_id, char* shared_memory){
    FILE* file = fopen(TMP_FILE, "w");
    fprintf(file, "%d|%p", segment_id, shared_memory);
    fclose(file);
}

void pass_msg_to_sh_memory(Message msg){
    const int msg_size = sizeof(Message);

    const int segment_id = allocate_sh_memory(msg_size);
    char* shared_memory = attach_sh_memory_segment(segment_id, msg_size);
    strcpy(shared_memory, msg.msg);

	write_info(segment_id, shared_memory);
}
