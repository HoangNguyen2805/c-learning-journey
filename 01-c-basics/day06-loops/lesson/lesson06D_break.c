#include <stdio.h>

int main() {

    printf("--- Break Example ---\n");

    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break;
        }

        printf("%d\n", i);
    }

    printf("Program finished.\n");

    return 0;
}