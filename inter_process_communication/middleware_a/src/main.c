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
	Message msg;
	
	msgrcv(msqid, &msg, sizeof(msg), 1, 0);

	printf("Middleware A\n");
	printf("%s\n", msg.msg);
	return 0;
}
