#ifndef PROJECT2_INC_SHARED_MEMORY_H_
#define PROJECT2_INC_SHARED_MEMORY_H_

#define _GNU_SOURCE

#include <sys/shm.h>

int allocate_sh_memory(size_t size);

pid_t* attach_sh_memory_segment(int segment_id, size_t expected_size);

#endif  // PROJECT2_INC_SHARED_MEMORY_H_
