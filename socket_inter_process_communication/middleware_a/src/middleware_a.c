#include "middleware_a.h"

void create_socket_file_descriptor() {
    // Creating socket file descriptor
	// Parameters(domain, type, protocol)
    if ((server_fd = socket(AF_INET, SOCK_STREAM, SOCKET_PROTOCOL)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
}

void attach_socket_to_port(int server_fd, int opt, Message msg) {
    // Forcefully attaching socket to the PORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the PORT
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, BACKLOG) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read(new_socket, buffer, BUFFER_SIZE);
    //fprintf(stdout,"%s\n",buffer);
    send(new_socket, msg.msg, strlen(msg.msg), SOCKET_FLAG);
}

int server(Message msg)
{
	opt = OPT_VALUE;
	addrlen = sizeof(address);
	buffer;

	create_socket_file_descriptor();

	attach_socket_to_port(server_fd, opt, msg);

    fprintf(stdout, "Message sent from MIDDLEWARE A.\n");
    return 0;
}
