#include "middleware_b.h"

int main() {

	fprintf(stderr, "Middleware B started.\n");
	
    // Better this be here because will need this information in this function
    void *address;
    int segment_id;
    fill_info(&segment_id, &address);

	signal(SIGINT, SIG_IGN);

	do {
        Message msg;
        msg.mtype = NORMAL_MESSAGE_TYPE;

		char *ptr_msg;
		get_msg_from_sh(segment_id, &address, &ptr_msg); 
		strcpy(msg.msg, ptr_msg);
		free(ptr_msg);

		fprintf(stderr, "Sending messsage from MIDDLEWARE B...\n");

        int msqid = create_message_queue(ARB_FILE, ARB_CHAR_B);
	    sending_message(msqid, &msg, FLAG);

		fprintf(stderr, "Message sent from MIDDLEWARE B\n");
	} while(1);

	return 0;
}
