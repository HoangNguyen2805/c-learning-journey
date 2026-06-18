#include <stdio.h>

int main() {

    printf("--- Continue Example ---\n");

    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;
        }

        printf("%d\n", i);
    }

    printf("Program finished.\n");

    return 0;
}