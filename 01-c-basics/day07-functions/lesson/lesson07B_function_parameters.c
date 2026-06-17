#include <stdio.h>

void printNumber(int number) {
    printf("The number is: %d\n", number);
}

int main() {
    printf("--- Function Parameters ---\n");

    printNumber(5);
    printNumber(10);
    printNumber(25);

    printf("Program finished.\n");

    return 0;
}