#ifndef _GNU_SOURCE
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define ARB_NUMBER 1
#define FLAG 0
#define MESSAGE_SIZE 101
#define FILE_PATH "/bin/ls"
#define ARB_CHAR_A 'j'
#define ARB_CHAR_B 'o'
#define NORMAL_MESSAGE_TYPE 1
#define PWD getenv("PWD")

typedef struct Message {
    long mtype;
    char msg[MESSAGE_SIZE];
} Message;

// Returns msqid.
int create_message_queue(char *file_path, char ch);

void invalid_exit_handling(int signal);

// Return amount of bytes sent
int receiving_message(int msqid, Message *msg, int arb_number, int flag);

void sending_message(int msqid, Message *msg, int flag);

void delete_message_queue(int msqid);

char *remove_last_from_path(char* str);

#endif
