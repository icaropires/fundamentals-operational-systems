#ifndef MIDDLEWARE_B
#define MIDDLEWARE_B

#include "../../utils/utils.h"

// Returns -1 if problem, else 0.
int sending_message(int msqid, Message *msg, int flag);
    
#endif
