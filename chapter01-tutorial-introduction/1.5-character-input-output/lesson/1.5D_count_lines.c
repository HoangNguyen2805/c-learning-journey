#include <stdio.h>

int main() {
    int c;
    int lines = 0;

    printf("Type something, then press Ctrl + D to stop:\n");

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    // count only "\n"
    printf("\nLines: %d\n", lines);

    return 0;
}