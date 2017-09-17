#include "middleware_a.h"

// Remove later
int create_message_queue(char *file_path, char ch) {
    key_t key = ftok(file_path, ch);
    int msqid = msgget(key, 0666 | IPC_CREAT);

    return msqid;
}

int receiving_message(int msqid, Message *msg, int arb_number, int flag) {
    int is_ok = -1;

    printf("%d lala \n", msg);

    msgrcv(msqid, msg, sizeof(Message), arb_number, flag);
    is_ok = 0;
    fprintf(stdout, "oi");

    return is_ok;
}
