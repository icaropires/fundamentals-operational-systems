#include "../../utils/utils.h"

int main() {
	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);
	Message msg;
	pid_t pid;
	char *path = strcat(PWD,"/../middleware_b/bin/middleware_b");
	path = remove_last_from_path(path);
	
	fprintf(stdout, "Receiving message in HOST B...\n");

	pid = fork();
	// Parent process.
	if(pid) {
		do {
			receiving_message(msqid, &msg, ARB_NUMBER, FLAG);
			fprintf(stdout, "Message: %s\n", msg.msg);
		} while(1);
	// Child process.
	} else {
		execvp(path, NULL);
	}



	return 0;
}
