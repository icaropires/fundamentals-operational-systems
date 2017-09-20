#ifndef MIDDLEWARE_A_H
#define MIDDLEWARE_B_H

#include <string.h>

#include "../../utils/utils.h"

char* attach_sh_memory_segment(int segment_id, void* address);

void fill_info(int *pid, int *segment_id, void **address);

char* get_msg_from_sh_memory();

#endif
