#include "host_a.h"
#include <string.h>

int main() {
    int msqid = create_message_queue(FILE_PATH, ARB_CHAR_A);

	Message msg = {1, "Message_test_1."};

	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Type END to stop sending.\n");
	fprintf(stdout, "Sending messsage from HOST A...\n");
	char aux[MESSAGE_SIZE];
	do {
		scanf("%s", aux);
		strcpy(msg.msg, aux);
    	sending_message(msqid, &msg, FLAG);
	} while(strcmp(aux, "END"));

	fprintf(stdout, "All messages sent from HOST A\n");

	return 0;
}
