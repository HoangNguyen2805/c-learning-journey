#include <stdio.h>

void changeNumber(int x);

int main() {
    int number = 5;

    printf("Before function call: %d\n", number);

    changeNumber(number);

    printf("After function call: %d\n", number);

    return 0;
}

void changeNumber(int x) {
    x = 100;
    printf("Inside function: %d\n", x);
}