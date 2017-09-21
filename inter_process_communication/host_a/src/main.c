#include "host_a.h"

int main() {
    // For generating unique keys
    generate_arb_file();

	int msqid = create_message_queue(ARB_FILE, ARB_CHAR_A);
	fprintf(stderr, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stderr, "Type END to stop sending.\n");
	fprintf(stderr, "Sending messsage from HOST A...\n");

    char msg_aux[MESSAGE_SIZE];

	pid_t pid = fork();
	if(pid) {
        signal(SIGINT, invalid_exit_handling);
        signal(SIGTERM, invalid_exit_handling);
		do {
			fgets(msg_aux, sizeof(msg_aux), stdin);
            msg_aux[strcspn(msg_aux, "\n")] = 0;  // Remove \n

			if(!strcmp(msg_aux, "END")){
				break;	
			}

            Message msg = {NORMAL_MESSAGE_TYPE, "Message_test_1."};
			strcpy(msg.msg, msg_aux);

			sending_message(msqid, &msg, FLAG);
		} while(1);

		kill(pid, SIGTERM);
		delete_message_queue(msqid);
	} else {
        char *path = strcat(PWD,"/../middleware_a/bin/middleware_a");
        path = remove_last_from_path(path);

		if(execvp(path, (char * const*){NULL}) == -1) {
			perror("Can't start middleware_A");
		}
	}

	return 0;
}
