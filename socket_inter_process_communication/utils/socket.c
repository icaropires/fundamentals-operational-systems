#include "socket.h"

int valread;
struct sockaddr_in address;
char buffer[BUFFER_SIZE];

int create_socket(int one_socket) {
	if ((one_socket = socket(AF_INET, SOCK_STREAM, SOCKET_PROTOCOL)) < 0) {   
        perror("Socket creation error");
        one_socket = -1; 
    } 
	return one_socket;
}
