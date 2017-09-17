#include "host_a.h"

int main() {
    int msqid = create_message_queue("/bin/ls", 'j');

	Message msg = {1, "Message_test_1."};

	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Sending messsage from HOST A...\n");

    sending_message(msqid, &msg, 0);

	fprintf(stdout, "Message sent from HOST A\n");

	return 0;
}
