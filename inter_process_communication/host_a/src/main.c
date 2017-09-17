#include "host_a.h"

int main() {
    int msqid = create_message_queue("/bin/ls", 'j');

	Message msg = {1, "Message_test_1."};

	fprintf(stdout, "Sending messsage from HOST A...\n");
    is_error = sending_message(msqid, &msg, 0);
    assert(is_error == 0);

	fprintf(stdout, "Message sent from HOST A\n");

	return 0;
}
