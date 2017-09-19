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

void sending_message(int msqid, Message *msg, int flag) {
    assert(msg != NULL);
	assert(msg->mtype >= 0);

    if(msgsnd(msqid, msg, sizeof(Message), flag) != -1) {
        /* Nothing */
    } else {
        perror("Error while sending message");
		exit(1);
    }
}

int receiving_message(int msqid, Message *msg, int arb_number, int flag) {
    assert(msg != NULL);
	assert(msg->mtype >= 0);

	// Check if there are messages on this queue.
	struct msqid_ds buf;
	if(!msgctl(msqid, IPC_STAT, &buf)){
		fprintf(stdout, "Waiting for messages...\n");
	} else {
		perror("Couldn't check this queue");
		exit(1);
	}

	// Receive message
	int bytes = msgrcv(msqid, msg, sizeof(Message), ARB_NUMBER, FLAG);

	// Check if message could be sent
    if(bytes != -1){
		return bytes;	
	} else {
		perror("Message couldn't be sent");
		exit(1);
	}
}

char *remove_last_from_path(char* str){
	int i;
	for(i = 0; str[i] != '\0'; ++i){
		int u = 0;
		if(str[i] == '/'){
			u = i;
		}
	}
	str[i] = '\0';
	return str;
}

