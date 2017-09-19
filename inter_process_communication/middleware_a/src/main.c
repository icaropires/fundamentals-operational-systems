#include "middleware_a.h"

int main() {

	fprintf(stdout, "Receiving message in MIDDLEWARE A...\n");

	do {
        Message msg;
        int msqid = create_message_queue(FILE_PATH, ARB_CHAR_A);

		receiving_message(msqid, &msg, ARB_NUMBER, FLAG);
		pass_msg_to_sh_memory(msg);

		if(!strcmp(msg.msg, "END")) {
			break;
		}
	} while(1);

	fprintf(stdout, "All messages Received.\n");

	return 0;
}
