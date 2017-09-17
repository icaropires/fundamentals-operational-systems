#ifndef _GNU_SOURCE
#define _GNU_SOURCE

#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARB_NUMBER 1
#define FLAG 0
#define MESSAGE_SIZE 101
#define FILE_PATH "/bin/ls"
#define ARB_CHAR_A 'j'
#define ARB_CHAR_B 'o'

typedef struct Message {
    long mytype;
    char msg[MESSAGE_SIZE];
} Message;

// Returns msqid.
int create_message_queue(char *file_path, char ch);

#endif
