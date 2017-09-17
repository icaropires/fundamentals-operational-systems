#include "host_b.h"
#include "../../utils/utils.c"

int receiving_message(int msqid, Message *msg, int arb_number, int flag) {

	// Check if there are messages on this queue.
	struct msqid_ds buf;
	if(!msgctl(msqid, IPC_STAT, &buf)){
		fprintf(stdout, "There is no messages on this queue, waiting...\n");
	} else {
		perror("Couldn't check this queue");
		exit(1);
	}

	int bytes = msgrcv(msqid, msg, sizeof(Message), ARB_NUMBER, FLAG);
    if(bytes != -1){
		return bytes;	
	} else {
		perror("Message couldn't be sent");
		exit(1);
	}
}
