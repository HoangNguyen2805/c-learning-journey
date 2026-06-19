#include <stdio.h>

int main() {
    int c;
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    printf("Type something, then press Ctrl + D to stop:\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            newlines++;
        }
    }

    printf("\nBlanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}