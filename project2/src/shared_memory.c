#include "../inc/utils.h"
#include "../inc/shared_memory.h"

int allocate_sh_memory(size_t size){
    fprintf(stderr, "\nAllocating shared memory area...\n");

    const int segment_id = shmget(IPC_PRIVATE,
                                  size,
                                  IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR); 

    if(segment_id != -1){
        fprintf(stderr, "Shared memory area creared: %d\n", segment_id);
    } else {
        perror("Couldn't create a shared memory area");
		exit(1);
    }

    return segment_id;
}

pid_t* attach_sh_memory_segment(int segment_id){
    fprintf(stderr, "\nAttaching to shared memory area...\n");

    pid_t *shared_memory = (pid_t*) shmat(segment_id, NULL, 0);

    if(shared_memory != (pid_t*) -1){
        fprintf(stderr, "%d to shared memory area.\n", getpid());
    } else {
        perror("%d couldn't attach to shared memory area");
		exit(1);
    }

    return shared_memory;
}

void deallocate_sh_memory(int segment_id){
	fprintf(stderr, "\nDeallocting shared memory %d\n", segment_id);

	if(shmctl(segment_id, IPC_RMID, 0) != -1){
		fprintf(stderr, "Shared memory deallocated\n");
	} else {
		perror("Couldn't deallocate shared_memory");
	}
}
