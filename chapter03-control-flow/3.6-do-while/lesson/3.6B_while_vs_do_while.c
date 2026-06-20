#include <stdio.h>

int main() {
    int a = 10;
    int b = 10;

    printf("While loop with false condition:\n");

    while (a < 5) {
        printf("This while loop runs.\n");
        a++;
    }

    printf("The while loop did not run.\n");

    printf("\nDo-while loop with false condition:\n");

    do {
        printf("This do-while loop runs once.\n");
        b++;
    } while (b < 5);

    printf("The do-while loop stopped after checking the condition.\n");

    return 0;
}