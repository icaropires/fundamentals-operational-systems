#include <host_b.h>

int SECOND_MSQID;

pid_t CHILD_PID;

void binary_semaphore_deallocate(int semid){
	int SEMNUM_TH = 0;
	union semun ignored_argument;

	int code = semctl (semid, SEMNUM_TH, IPC_RMID, ignored_argument);

    if(code == -1){
        perror("Was not possible to allocate semaphores");
    }
}

void handle_finish(int signal){
	kill(CHILD_PID, SIGTERM);
    delete_message_queue(SECOND_MSQID);
    binary_semaphore_deallocate(SEMID);
	remove(TMP_FILE);
	remove(ARB_FILE);
}
