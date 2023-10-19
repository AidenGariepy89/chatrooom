#include <stdio.h>
#include <time.h>
#include <stdint.h>

int lcg(long int x0, int a, int b, int m) {
    printf("%d, %d, %d, %d \n", x0, a, b, m);
    for (int i=0; i<24; i++) {

        x0 = (a * x0 + b) % m;
        
        printf("%d\n", x0);
    }
    return 0;
}

int genPrime(void) {
    int n;
    int k;
    int out;
    time_t result = time(NULL);
    // if(result != (time_t)(-1))
    //     printf("The current time is %s(%jd seconds since the Epoch)\n",
    //            asctime(gmtime(&result)), (intmax_t)result);
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char buff[100];
    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
    // fgets(n, 8, stdin);
    // scanf("%d", &n);
    // scanf("%d", &k);
    // printf("%d", n);
    // printf("%d\n", k);
    return 0;
}

