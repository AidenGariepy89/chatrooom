#include <stdlib.h> // C Standard Library
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "number_game.h"

void testing();

int main() {
    run_game();

    return 0;
}

int cmpfunc(const void* a, const void* b) { // Compares 2 ints
    return *(int*)a - *(int*)b;
}

void testing() {
    // String to Int
    char num_str[] = "54321";
    int num = atoi(num_str);
    printf("%d\n", num);

    // Sorting
    int vars[] = { 1, 8, 5, 2, 5 };
    qsort(vars, 5, sizeof(int), cmpfunc); // quick sort

    for (int i = 0; i < 5; i++) {
        printf("Sorted: %d\n", vars[i]);
    }

    // Random Numbers
    srand(time(NULL));
    int random = rand();
    printf("Random number: %d\n", random);

    // String Append
    char name1[10] = "Aiden";
    char name2[5] = "Jack";
    strncat(name1, name2, 4); // Length is length of appended string
    printf("%s\n", name1);

    // String Copy
    char src[40];
    char dest[11]; // Very important to leave last digit for \0 - null terminating char.

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "Testing testing 1 2 3");
    strncpy(dest, src, 10);
    printf("%s\n", dest);

    // String token split
    printf("---Token Split---\n");

    char str[80] = "Hello darkness my old friend";
    const char delim[2] = " ";
    char* token;

    token = strtok(str, delim);
    while (token != NULL) {
        printf("%s\n", token);

        token = strtok(NULL, delim); // pass in NULL to continue until end of string
    }

    // Variable overflow
    size_t test = 0;
    printf("%zu\n", test - 1);
}
