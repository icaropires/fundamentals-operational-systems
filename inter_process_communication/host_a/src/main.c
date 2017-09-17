#include "host_a.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct message {
	long mtype;
	char msg[101];
} Message;

int main() {
	// char 'j' about xanayna.
	key_t key = ftok("/bin/ls", 'j');
	int msqid = msgget(key, 0666 | IPC_CREAT);

	Message msg = {1, "Message_test_1."};

	msgsnd(msqid, &msg, sizeof(msg), 0);

	printf("Main file\n");
	return 0;
}
