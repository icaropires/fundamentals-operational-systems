#include "host_b.h"

int main() {
	fprintf(stdout, "Receiving message in HOST B...\n");

	// Defined on host_a.h
	SECOND_MSQID = create_message_queue(FILE_PATH, ARB_CHAR_B);

	pid_t pid = fork();
    CHILD_PID = pid;

	if(pid) {
		signal(SIGINT, handle_finish);
		signal(SIGTERM, handle_finish);
		do {
            Message msg;
			receiving_message(SECOND_MSQID, &msg, ARB_NUMBER, FLAG);

			fprintf(stdout, "Message: %s\n", msg.msg);
		} while(1);
	} else {
		char *path = strcat(PWD, "/../middleware_b/bin/middleware_b");
		path = remove_last_from_path(path);
	
		if(execvp(path, (char * const*){NULL}) == -1) {
			perror("Can't start middleware_B");
		}
	}

	return 0;
}
