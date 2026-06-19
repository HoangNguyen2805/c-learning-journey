#include <stdio.h>

int main() {
    int c;

    printf("Type something, then press Ctrl + D to stop:\n");

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    printf("\nProgram finished.\n");

    return 0;
}