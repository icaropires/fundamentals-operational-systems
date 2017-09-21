#include "host_b.h"

int main() {
	char *path = strcat(PWD,"/../middleware_b/bin/middleware_b");
	path = remove_last_from_path(path);
	
	fprintf(stdout, "Receiving message in HOST B...\n");

	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);
	pid_t pid = fork();

	if(pid) {
		do {
            Message msg;
			receiving_message(msqid, &msg, ARB_NUMBER, FLAG);
			if(!strcmp(msg.msg, "END")){
				break;
			}
			fprintf(stdout, "Message: %s\n", msg.msg);
		} while(1);
	} else {
		if(execvp(path, (char * const*){NULL}) == -1) {
			perror("Can't start middleware_A");
		}
	}

	return 0;
}
