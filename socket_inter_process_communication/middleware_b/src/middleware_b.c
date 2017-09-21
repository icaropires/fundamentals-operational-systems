// Client side C/C++ program to demonstrate Socket programming
#include "middleware_b.h"

int client_socket;
struct sockaddr_in serv_addr;

void convert_ip_to_binary() {
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, IP_ADDRESS, &serv_addr.sin_addr) <= 0) {
        perror("\nInvalid address/ Address not supported \n");
    }
}

void connect_socket(struct sockaddr_in serv_addr) {
    if (connect(client_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("\nConnection Failed \n");
    }
}

void send_message(int client_socket, Message msg) {
    send(client_socket, msg.msg, strlen(msg.msg), SOCKET_FLAG);
    printf("Message sent from MIDDLEWARE B\n");
    valread = read(client_socket, buffer, BUFFER_SIZE);
    printf("%s\n",buffer );
}

void client(Message msg) {
	client_socket = create_socket(client_socket);
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
	convert_ip_to_binary();
  
	connect_socket(serv_addr);

	send_message(client_socket, msg);

}
