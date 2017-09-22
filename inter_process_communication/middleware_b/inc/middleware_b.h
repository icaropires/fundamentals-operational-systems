#ifndef MIDDLEWARE_A_H
#define MIDDLEWARE_B_H

#include <string.h>

#include "../../utils/utils.h"

extern int SEMID;

void fill_info(int *segment_id, void **address);

char* get_msg_from_sh(int segment_id, void** address);

#endif
