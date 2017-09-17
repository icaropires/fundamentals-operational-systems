#include "middleware_b.h"

int main() {
    int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);

	Message msg = {1, "Message_test_2."};

	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Sending messsage MIDDLEWARE B...\n");

    sending_message(msqid, &msg, FLAG);

	fprintf(stdout, "Message sent from MIDDLEWARE B\n");

	return 0;
}
