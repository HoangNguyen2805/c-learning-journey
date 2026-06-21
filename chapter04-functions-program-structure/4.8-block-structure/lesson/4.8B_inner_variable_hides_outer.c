#include <stdio.h>

int main() {
    int number = 100;

    printf("Outer number: %d\n", number);

    {
        int number = 50;

        printf("Inner number: %d\n", number);
    }

    printf("Outer number again: %d\n", number);

    return 0;
}