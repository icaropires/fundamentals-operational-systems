#ifndef MIDDLEWARE_A_H
#define MIDDLEWARE_B_H

#include <string.h>

#include "../../utils/utils.h"

void fill_info(pid_t host_b_pid, pid_t *host_a_pid, int *segment_id, void **address);

void get_msg_from_sh(int segment_id, void** address, char** ptr_msg);

#endif
