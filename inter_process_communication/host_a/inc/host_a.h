#ifndef HOST_A
#define HOST_A

#include "../../utils/utils.h"

// Returns -1 if problem, else 0.
int sending_message(int msqid, Message *msg, int flag);
    
#endif
