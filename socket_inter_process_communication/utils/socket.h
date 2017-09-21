#ifndef SOCKET_H
#define SOCKET_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SOCKET_PROTOCOL 0
#define SOCKET_FLAG 0

extern int valread;
extern struct sockaddr_in address;
extern char buffer[BUFFER_SIZE];

int create_socket(int one_socket);

#endif
