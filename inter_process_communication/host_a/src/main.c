#include "host_a.h"

int main() {
    int msqid = create_message_queue(FILE_PATH, ARB_CHAR);

	Message msg = {1, "Message_test_1."};

	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Sending messsage from HOST A...\n");

    sending_message(msqid, &msg, FLAG);

	fprintf(stdout, "Message sent from HOST A\n");

	return 0;
}
