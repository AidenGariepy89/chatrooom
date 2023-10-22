#include <stdio.h>
#include <string.h>

#include "tcp_client.h"
#include "tcp_server.h"


int main() {
    // figure out what tcp connection to start
    printf("Start a server or client? (s/c/q) ");
    char choice[8]; 
    fgets(choice, sizeof(choice), stdin);
    // process overflow input
    if (choice[strlen(choice)] == '\0' && choice[strlen(choice) - 1] != '\n') {
        int ch;
        while ((ch = fgetc(stdin)) != '\n' && ch != EOF);
    }
    // process input 
    if (choice[1] == '\n') {
        switch (choice[0]) {
            case 's':
                printf("Booting up a server on port 9002...\n");
                tcp_server(9002, "Hello there human being");
                break;
            case 'c':
                printf("Booting up a client on port 9002...\n");
                tcp_client(9002);
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

    


    return 0;
}
