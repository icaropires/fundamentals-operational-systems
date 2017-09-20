#include "../../utils/utils.h"

int main() {
	char *path = strcat(PWD,"/../middleware_a/bin/middleware_a");
	path = remove_last_from_path(path);

	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_A);
	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Type END to stop sending.\n");
	fprintf(stdout, "Sending messsage from HOST A...\n");

    char msg_aux[MESSAGE_SIZE];

	pid_t pid = fork();
	if(pid) {
		// Dad handle signals
        signal(SIGINT, invalid_exit_handling);
        signal(SIGTERM, invalid_exit_handling);
		do {
			fgets(msg_aux, sizeof(msg_aux), stdin);
            msg_aux[strcspn(msg_aux, "\n")] = 0;

            Message msg = {NORMAL_MESSAGE_TYPE, "Message_test_1."};
			strcpy(msg.msg, msg_aux);

			sending_message(msqid, &msg, FLAG);
		} while(strcmp(msg_aux, "END"));
	} else {
		if(execvp(path, (char * const*){NULL}) == -1) {
			perror("Can't start middleware_A");
		}
	}

    delete_message_queue(msqid);
	return 0;
}
