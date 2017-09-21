#include <host_b.h>

int SECOND_MSQID;
pid_t CHILD_PID;

void handle_finish(int signal){
	kill(CHILD_PID, SIGTERM);
    delete_message_queue(SECOND_MSQID);
	remove("../address");
}
