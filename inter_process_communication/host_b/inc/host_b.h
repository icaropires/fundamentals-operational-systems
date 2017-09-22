#ifndef HOST_B_H
#define HOST_B_H

#include <../../utils/utils.h>
#include <../../middleware_b/inc/middleware_b.h>

// Needed, because can't send parameters to signal handlers functions
extern int SECOND_MSQID;

extern pid_t CHILD_PID;

extern int SEMID;

void close_sh_memory();

void handle_finish(int signal);

void binary_semaphore_deallocate(int semid);

#endif
