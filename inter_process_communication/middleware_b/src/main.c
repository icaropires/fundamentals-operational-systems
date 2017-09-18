#include "middleware_b.h"

int main() {
    int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);

	Message msg;

	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Sending messsage MIDDLEWARE B...\n");

	strcpy(msg.msg, get_msg_from_sh_memory());

    sending_message(msqid, &msg, FLAG);

	return 0;
}
