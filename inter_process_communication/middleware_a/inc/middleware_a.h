#ifndef MIDDLEWARE_A_H
#define MIDDLEWARE_A_H

#include <string.h>

#include "../../utils/utils.h"

int allocate_sh_memory(size_t size);

char* attach_sh_memory_segment(int segment_id, size_t expected_size);

void write_info(int segment_id, char* shared_memory);

void pass_msg_to_sh_memory(Message msg);

#endif
