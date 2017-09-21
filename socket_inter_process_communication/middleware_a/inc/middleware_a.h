#ifndef MIDDLEWARE_A_H
#define MIDDLEWARE_A_H

#include "../../utils/utils.h"
#include "../../utils/socket.h"

#define BACKLOG 3
#define OPT_VALUE 0

extern int server_fd, new_socket;
extern int opt;
extern int addrlen;

void server();

void create_socket_file_descriptor();

void attach_socket_to_port(int server_fd, int opt, Message msg);

#endif
