#include "host_a.h"

int create_message_queue(char *file_path, char ch) {
    key_t key = ftok(file_path, ch);
    int msqid = msgget(key, 0666 | IPC_CREAT);

    return msqid;
}

int sending_message(int msqid, Message *msg, int flag) {
    assert(msg != NULL);

    int is_ok = -1;

    printf("%d lala \n", msg);

    if(msgsnd(msqid, msg, sizeof(Message), flag) != -1) {
        is_ok = 0;
    } else {
        perror("Error while sending message.");
    }

    return is_ok;
}
