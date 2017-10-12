#ifndef PROJECT2_INC_MESSAGE_H_
#define PROJECT2_INC_MESSAGE_H_

#define _GNU_SOURCE

#include <sys/msg.h>

#include "../inc/utils.h"

#define NORMAL_MESSAGE_TYPE 1
#define MESSAGE_SIZE 101
#define FLAG 0

typedef struct Message {
    long mtype;
    char msg[MESSAGE_SIZE];
} Message;

int create_message_queue(char *file_path, char ch);

int receiving_message(int msqid, Message *msg, int arb_number, int flag);

void sending_message(int msqid, Message *msg, int flag);

void delete_message_queue(int msqid);

#endif  // PROJECT2_INC_MESSAGE_H_
