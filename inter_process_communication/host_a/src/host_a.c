#include "host_a.h"

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

int sending_message(int msqid, Message *msg, int flag) {
    assert(msg != NULL);

    if(msgsnd(msqid, msg, sizeof(Message), flag) != -1) {
		return 0;
    } else {
        perror("Error while sending message");
		exit(1);
    }
}
