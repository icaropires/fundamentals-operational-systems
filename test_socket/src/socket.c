#include <socket.h>

int server(int client_socket) {
    while (1) {
        int length;
        char *text;

        if (read(client_socket, &length, sizeof(length)) == 0) {
            return 0;
        }
        text = (char*) malloc(length);
        read(client_socket, text, length);
        printf("%s\n", text);
        free(text);
        if(!strcmp(text, "quit")) {
            return 1;
        }
    }
}

