#include "middleware_a.h"

int main() {

	fprintf(stderr, "Receiving message in MIDDLEWARE A...\n");

	int msqid = create_message_queue(ARB_FILE, ARB_CHAR_A);

	// Child ignores signals for exit
	signal(SIGINT, SIG_IGN);
	do {
        Message msg;

		receiving_message(msqid, &msg, ARB_NUMBER, FLAG);
		if(!strcmp(msg.msg, "END")) {
			break;
		}
		pass_msg_to_sh_memory(msg);
	} while(1);

	return 0;
}
