#include "middleware_b.h"

int main() {

	fprintf(stderr, "Middleware B started.\n");
	
    // Better this be here because will need this information in this function
    void *address;
    int segment_id;
    pid_t host_a_pid;
    pid_t host_b_pid;
    fill_info(host_b_pid, &host_a_pid, &segment_id, &address);

	signal(SIGINT, SIG_IGN);

	do {
        Message msg;
        msg.mtype = NORMAL_MESSAGE_TYPE;

		char *ptr_msg;
		get_msg_from_sh(segment_id, &address, &ptr_msg); 
		strcpy(msg.msg, ptr_msg);
		free(ptr_msg);

		fprintf(stderr, "Sending messsage from MIDDLEWARE B...\n");

        int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);
	    sending_message(msqid, &msg, FLAG);

		fprintf(stderr, "Message sent from MIDDLEWARE B\n");
	} while(1);

	return 0;
}
