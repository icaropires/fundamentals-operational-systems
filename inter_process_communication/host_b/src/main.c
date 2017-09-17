#include "host_b.h"

int main() {
	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);

	Message msg;
	
	fprintf(stdout, "Receiving message in HOST B...\n");
	receiving_message(msqid, &msg, ARB_NUMBER, FLAG);

	fprintf(stdout, "%s\n", msg.msg);

	return 0;
}
