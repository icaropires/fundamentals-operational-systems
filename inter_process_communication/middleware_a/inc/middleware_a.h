#ifndef MIDDLEWARE_A 
#define MIDDLEWARE_A

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <assert.h>

typedef struct Message {
    long mytype;
    char msg[101];
} Message;

int is_error;

// Returns msquid.
int create_message_queue(char *file_path, char ch);

// Returns -1 if problem, else 0.
int receiving_message(int msqid, Message *msg, int arb_number, int flag);
    
#endif
