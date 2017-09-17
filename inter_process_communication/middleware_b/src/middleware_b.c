#include "middleware_b.h"
#include "../../utils/utils.c"

int sending_message(int msqid, Message *msg, int flag) {
    assert(msg != NULL);

    if(msgsnd(msqid, msg, sizeof(Message), flag) != -1) {
		return 0;
    } else {
        perror("Error while sending message");
		exit(1);
    }
}
