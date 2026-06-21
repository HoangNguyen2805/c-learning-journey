#include <stdio.h>

#define square(x) ((x) * (x))

int main() {
    int number = 5;
    int result;

    result = square(number);

    printf("Number: %d\n", number);
    printf("Square: %d\n", result);
    printf("square(1 + 2): %d\n", square(1 + 2));

    return 0;
}