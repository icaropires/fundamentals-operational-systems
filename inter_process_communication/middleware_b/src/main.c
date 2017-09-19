#include "middleware_b.h"

int main() {

	fprintf(stdout, "Middleware B started.\n");

	do {
        Message msg;
        msg.mtype = NORMAL_MESSAGE_TYPE;

		strcpy(msg.msg, get_msg_from_sh_memory());
		fprintf(stdout, "Sending messsage from MIDDLEWARE B...\n");

        int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);
	    sending_message(msqid, &msg, FLAG);

		fprintf(stdout, "Message sent from MIDDLEWARE B\n");
		if(strcmp(msg.msg, "EDN")) {
			break;
		}
	} while(1);

	close_sh_memory();

	return 0;
}
