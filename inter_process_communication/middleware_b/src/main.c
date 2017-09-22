#include "middleware_b.h"

int main() {

	fprintf(stderr, "Middleware B started.\n");
	
	SEMID = create_semaphores(ARB_FILE, IPC_CREAT); 

	binary_semaphore_down(SEMID); // Unlock A, Value = 0
	binary_semaphore_up(SEMID); // Value = 1
	semaphore_wait_for_zero(SEMID); // Block this till 0
	
    // Better this be here because will need this information in this function
    void *address;
    int segment_id;
    fill_info(&segment_id, &address);

	signal(SIGINT, SIG_IGN);

	fprintf(stderr, "Middleware B will use semaphore of semid %d\n", SEMID);

	do {
        Message msg;
        msg.mtype = NORMAL_MESSAGE_TYPE;

		char* shared_memory =  get_msg_from_sh(segment_id, &address);
		strcpy(msg.msg, shared_memory);

		binary_semaphore_down(SEMID); // Unlock A, Value = 0
		binary_semaphore_up(SEMID); // Value = 1
		semaphore_wait_for_zero(SEMID); // Block this till 0

		fprintf(stderr, "Sending messsage from MIDDLEWARE B...\n");
        int msqid = create_message_queue(ARB_FILE, ARB_CHAR_B);
	    sending_message(msqid, &msg, FLAG);

		shmdt(shared_memory);
		shmctl(segment_id, IPC_RMID, 0);


		fprintf(stderr, "Message sent from MIDDLEWARE B\n");
	} while(1);

	return 0;
}
