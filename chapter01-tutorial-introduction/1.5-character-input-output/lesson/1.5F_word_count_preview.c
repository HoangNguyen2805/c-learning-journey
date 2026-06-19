#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c;
    int state;
    int words = 0;

    state = OUT;

    printf("Type something, then press Ctrl + D to stop:\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            words++;
        }
    }

    printf("\nWords: %d\n", words);

    return 0;
}