#ifndef MIDDLEWARE_A_H
#define MIDDLEWARE_A_H

#include "../../utils/utils.h"
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 101
#define PORT 8080
int server_fd,  new_socket, valread;
struct sockaddr_in address;
int opt;
int addrlen;
char buffer[BUFFER_SIZE];

char message[BUFFER_SIZE];

int server();

void create_socket_file_descriptor();

void attach_socket_to_port(int port, int server_fd, int opt);

#endif
