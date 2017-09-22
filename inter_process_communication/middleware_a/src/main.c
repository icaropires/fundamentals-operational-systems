#include "middleware_a.h"

int main() {

	fprintf(stderr, "Receiving message in MIDDLEWARE A...\n");

	int msqid = create_message_queue(ARB_FILE, ARB_CHAR_A);

	// Child ignores signals for exit
	signal(SIGINT, SIG_IGN);

	int semid = create_semaphores(ARB_FILE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR); 
	initialize_semaphores(semid);

	fprintf(stdout, "Waiting for B to connect\n");
	semaphore_wait_for_zero(semid); // Start blocked
	fprintf(stderr, "Middleware A will use semaphore of semid %d\n", semid);

	do {
        Message msg;

		receiving_message(msqid, &msg, ARB_NUMBER, FLAG);
		if(!strcmp(msg.msg, "END")) {
			break;
		}

		pass_msg_to_sh_memory(msg);

		binary_semaphore_down(semid); // Unlock B, Value = 0
		binary_semaphore_up(semid); // Value = 1
		semaphore_wait_for_zero(semid); // Block this till 0
	} while(1);

	return 0;
}
