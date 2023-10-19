#include "number_game.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// This is purely for c practice and learning.

int gen_answer() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int game_loop(int answer, int* tries) {
    printf("Guess a number between 1 and 100!\n");

    // Handle Input
    printf("> ");
    char input[64];
    int guess;
    if (NULL == fgets(input, sizeof(input), stdin)) {
        printf("Input error!\n");
        return GAME_STATE_CONTINUE;
    }

    if (input[strlen(input)] == '\0' && input[strlen(input) - 1] != '\n') {
        int ch;
        while ((ch = fgetc(stdin)) != '\n' && ch != EOF);
    }

    if (input[0] == 'q' && input[1] == '\n') {
        return GAME_STATE_EXIT;
    }

    if (1 != sscanf(input, "%d", &guess)) { // Converts input to int and checks if it is valid
        printf("Invalid input! Try again!\n");
        return GAME_STATE_CONTINUE;
    }

    // Interpret Answer
    if (guess == answer) {
        printf("Congradulations! You guessed the number in only %d tries!\n\n", *tries);
        return GAME_STATE_FINISH;
    }

    if (guess > answer) {
        printf("Too high! Try guessing a lower number...\n\n");
    } else {
        printf("Too low! Try guessing a higher number...\n\n");
    }

    (*tries)++;

    return GAME_STATE_CONTINUE;
}

void run_game() {
    printf("--- Welcome to the guessing game! ---\n");

    int correct_answer = gen_answer();
    int tries = 1;
    printf("Correct: %d\n", correct_answer);

    int state = GAME_STATE_CONTINUE;
    while (1) {
        state = game_loop(correct_answer, &tries);

        if (state == GAME_STATE_EXIT) {
            break;
        }
        if (state == GAME_STATE_FINISH) {
            printf("Continue playing? ");
            char input[16];
            if (NULL == fgets(input, sizeof(input), stdin)) {
                printf("Input error\n");
                exit(1);
            }
            if (input[0] != 'y') {
                break;
            }
        }
    }
}
