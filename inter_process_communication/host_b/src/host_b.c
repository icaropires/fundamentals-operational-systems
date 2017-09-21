#include <host_b.h>

int SECOND_MSQID;
pid_t CHILD_PID;

void binary_semaphore_down(int semid) {
    struct sembuf operations[1];

    operations[0].sem_num = 0;
    operations[0].sem_op = -1;
    operations[0].sem_flg = SEM_UNDO;

    if(semop(semid, operations, 1)){
       perror("Wasn't possible to down the semaphore");
    }
}

void handle_finish(int signal){
	kill(CHILD_PID, SIGTERM);
    delete_message_queue(SECOND_MSQID);
	remove(TMP_FILE);
	remove(ARB_FILE);
    // Delete semaphore
}
