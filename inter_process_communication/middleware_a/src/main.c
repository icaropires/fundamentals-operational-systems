#include "middleware_a.h"

int main() {
	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_A);

	Message msg;
	
	fprintf(stdout, "Receiving message in MIDDLEWARE A...\n");

	do {
		receiving_message(msqid, &msg, ARB_NUMBER, FLAG);
		pass_msg_to_sh_memory(msg);
		// fprintf(stdout, "%s\n", msg.msg);
		if(!strcmp(msg.msg, "END")) {
			break;
		}
	} while(1);

	fprintf(stdout, "All messages Received.\n");

	return 0;
}
