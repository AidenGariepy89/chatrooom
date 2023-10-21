#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "socket.h"

int tcp_client() {
    
    // create a socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (network_socket < 0) {
        fprintf(stderr, "Error creating socket (%d): %s\n", errno, strerror(errno));
        return 1;
    }

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // check for error with the connection
    if (connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error connecting to socket (%d): %s\n", errno, strerror(errno));
        return 1;
    }

    // recieve data from the server
    char server_response[256];
    if (recv(network_socket, &server_response, sizeof(server_response), 0) < 0) {
        fprintf(stderr, "Error recieving from socket (%d): %s\n", errno, strerror(errno));
        return 1;
    }

    // print out the server's response
    printf("The server sent the data: %s\n", server_response);
    
    // close the socket
    close(network_socket);

    return 0;
}
