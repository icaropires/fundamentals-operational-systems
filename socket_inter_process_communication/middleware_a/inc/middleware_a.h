#ifndef MIDDLEWARE_A_H
#define MIDDLEWARE_A_H

#include "../../utils/utils.h"
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SOCKET_PROTOCOL 0
#define BACKLOG 3
#define SOCKET_FLAG 0
#define OPT_VALUE 0

int server_fd,  new_socket, valread;
struct sockaddr_in address;
int opt;
int addrlen;
char buffer[BUFFER_SIZE];

char message[BUFFER_SIZE];

int server();

void create_socket_file_descriptor();

void attach_socket_to_port(int server_fd, int opt, Message msg);

#endif
