#include <stdio.h>

#define DEBUG

int main() {
    printf("Program started\n");

#ifdef DEBUG
    printf("Debug message: DEBUG is defined\n");
#endif

#ifndef RELEASE
    printf("RELEASE is not defined\n");
#endif

    printf("Program ended\n");

    return 0;
}