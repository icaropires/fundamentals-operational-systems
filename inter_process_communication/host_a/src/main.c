#include "../../utils/utils.h"

int main() {
	char *path = strcat(PWD,"/../middleware_a/bin/middleware_a");
	path = remove_last_from_path(path);

	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_A);
	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Type END to stop sending.\n");
	fprintf(stdout, "Sending messsage from HOST A...\n");

	pid_t pid;
    char aux[MESSAGE_SIZE];

	pid = fork();
	if(pid) {
		do {
			fgets(aux, sizeof(aux), stdin);

            Message msg = {NORMAL_MESSAGE_TYPE, "Message_test_1."};
			strcpy(msg.msg, aux);

			sending_message(msqid, &msg, FLAG);
		} while(strcmp(aux, "END"));
	} else {
		if(execvp(path, NULL) ==-1 ) {
			perror("Can't start middleware_A");
		}
	}

	//	fprintf(stdout, "All messages sent from HOST A\n");

	return 0;
}
