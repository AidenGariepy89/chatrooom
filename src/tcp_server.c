#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "socket.h"

int tcp_server() {
    // create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "Error creating socket (%d): %s", errno, strerror(errno));
        return 1;
    }

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error binding socket (%d): %s", errno, strerror(errno));
        return 1;
    }

    if (listen(server_socket, 5) < 0) {
        fprintf(stderr, "Error listening to socket (%d): %s", errno, strerror(errno));
        return 1;
    }

    char server_message[256] = "You have reached the server!";
    for (;;) {
        printf("Waiting for connection...\n");
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            fprintf(stderr, "Error accepting an incoming connection (%d): %s", errno, strerror(errno));
            return 1;
        }

        printf("Recieved client (%d)!\n", client_socket);

        // send the message
        send(client_socket, server_message, sizeof(server_message), 0);

        // close the client socket
        close(client_socket);
    }
}
