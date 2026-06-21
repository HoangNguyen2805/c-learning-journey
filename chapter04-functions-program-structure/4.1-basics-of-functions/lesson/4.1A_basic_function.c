#include <stdio.h>

void printMessage(void);

int main() {
    printf("Main starts.\n");

    printMessage();

    printf("Main ends.\n");

    return 0;
}

void printMessage(void) {
    printf("This message came from a function.\n");
}