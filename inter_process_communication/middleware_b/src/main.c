#include "middleware_b.h"

int main() {

	fprintf(stdout, "Middleware B started.\n");
	
    void *address;
    int pid, segment_id;

    fill_info(&pid, &segment_id, &address);
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
