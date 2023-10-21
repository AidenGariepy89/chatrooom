#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "socket.h"

int main() {
    // figure out what tcp connection to start
    printf("Start a server or client? (s/c/q) ");
    char choice[8]; 
    if (fgets(choice, sizeof(choice), stdin) == NULL) {
        // Print error
        fprintf(stderr, "Error getting input (%d): %s\n", errno, strerror(errno));
    }

    // process overflow input
    if (choice[strlen(choice)] == '\0' && choice[strlen(choice) - 1] != '\n') {
        int ch;
        while ((ch = fgetc(stdin)) != '\n' && ch != EOF);
    }

    int result;
    // process input 
    if (choice[1] == '\n') {
        switch (choice[0]) {
            case 's':
                printf("Booting up a server on port %d...\n", SERVER_PORT);
                result = tcp_server();
                break;
            case 'c':
                printf("Booting up a client on port %d...\n", SERVER_PORT);
                result = tcp_client();
                break;
            case 'q':
                printf("Goodbye\n");
                return 0;
                break;
            default:
                printf("Invalid Input idk how you expect me to know what to do with that\n");
                break;
        }
    }

    return result;
}
