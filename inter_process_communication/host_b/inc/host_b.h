#ifndef HOST_B 
#define HOST_B

#include "../../utils/utils.h"

// Returns -1 if problem, else 0.
int receiving_message(int msqid, Message *msg, int arb_number, int flag);
    
#endif
