#include "utils.h"

int create_message_queue(char *file_path, char ch) {
	assert(file_path != NULL);

	key_t key = ftok(file_path, ch);

	int msqid = msgget(key, 0666 | IPC_CREAT);
	if(msqid != -1){
		return msqid;
	} else {
		perror("Couldn't create message queue");
		exit(1);
	}
}
