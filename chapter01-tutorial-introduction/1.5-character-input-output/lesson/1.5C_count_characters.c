#include <stdio.h>

int main() {
    int c;
    int count = 0;

    printf("Type something, then press Ctrl + D to stop:\n");

    while ((c = getchar()) != EOF) {
        count++;
    }
    // getchar() counts letters and newline \n
    printf("\nCharacters: %d\n", count);

    return 0;
}