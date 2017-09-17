#include "host_a.h"

int create_message_queue(char *file_path, char ch) {
    key_t key = ftok(file_path, ch);
    int msqid = msgget(key, 0666 | IPC_CREAT);

    return msqid;
}

int sending_message(int msqid, Message *msg, int flag) {
    int is_ok = -1;

    if(msgsnd(msqid, msg->msg, sizeof(msg->msg), flag) != -1) {
        is_ok = 0;
    } else {
        perror("Error while sending message.");
    }

    return is_ok;
}
