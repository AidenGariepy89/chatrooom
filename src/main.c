#include <stdlib.h> // C Standard Library
#include <stdio.h>
#include "socket.h"

void testing();

int main() {
    testing();

    return 0;
}

int cmpfunc(const void* a, const void* b) { // Compares 2 ints
    return *(int*)a - *(int*)b;
}

void testing() {
    char num_str[] = "54321";
    int num = atoi(num_str);
    printf("%d\n", num);

    int vars[] = { 1, 8, 5, 2, 5 };
    qsort(vars, 5, sizeof(int), cmpfunc); // quick sort

    for (int i = 0; i < 5; i++) {
        printf("Sorted: %d\n", vars[i]);
    }

    size_t test = 0;
    printf("%zu\n", test - 1); // variable overflow
}
