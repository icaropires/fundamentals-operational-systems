#ifndef MIDDLEWARE_A
#define MIDDLEWARE_A

#include <string.h>

#include "../../utils/utils.h"

// Returns -1 if problem, else 0.
int receiving_message(int msqid, Message *msg, int arb_number, int flag);

int allocate_sh_memory(size_t size);

char* attach_sh_memory_segment(int segment_id, size_t expected_size);

void pass_msg_to_sh_memory(Message message);
    
#endif
