#include "middleware_a.h"

int main() {

	fprintf(stdout, "Receiving message in MIDDLEWARE A...\n");

	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_A);

	// Child ignores signals for exit
	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	do {
        Message msg;

		receiving_message(msqid, &msg, ARB_NUMBER, FLAG);
		pass_msg_to_sh_memory(msg);

		if(!strcmp(msg.msg, "END")) {
			break;
		}
	} while(1);

	return 0;
}
