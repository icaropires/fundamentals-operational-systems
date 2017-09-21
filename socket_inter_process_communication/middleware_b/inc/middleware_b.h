#ifndef MIDDLEWARE_B_H
#define MIDDLEWARE_B_H

#include "../../utils/utils.h"
#include "../../utils/socket.h"

#include <arpa/inet.h>

#define IP_ADDRESS "127.0.0.1"

extern int client_socket;
extern struct sockaddr_in serv_addr;

Message client(Message msg);

void convert_ip_to_binary();

void connet_socket(int client_socket, struct sockaddr_in serv_addr);

Message receive_message(int client_socket, Message msg);

#endif
