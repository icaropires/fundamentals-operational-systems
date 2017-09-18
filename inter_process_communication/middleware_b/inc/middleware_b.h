#ifndef MIDDLEWARE_B
#define MIDDLEWARE_B

#include <string.h>

#include "../../utils/utils.h"

// Returns -1 if problem, else 0.
int sending_message(int msqid, Message *msg, int flag);

char* attach_sh_memory_segment(int segment_id, void* address);

void close_sh_memory(int segment_id, char* shared_memory);
    
char* get_msg_from_sh_memory();

#endif
