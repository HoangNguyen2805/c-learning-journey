/*
1.5 practice.

Create:

chapter01-tutorial-introduction/1.5-character-input-output/practice/practice01_character_counter.c

Task:

Read input until Ctrl + D, then print:

Characters:
Lines:
Blanks:
Tabs:
Words:

Use:

getchar()
EOF
while loop
if / else if
IN / OUT for word counting

This practice combines all 1.5 lessons.

*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c;
    int characters = 0;
    int lines = 0;
    int blanks = 0;
    int tabs = 0;
    int words = 0;
    int state = OUT;

    printf("Type something, then press Ctrl + D to stop:\n");

    while ((c = getchar()) != EOF) {
        characters++;

        if (c == '\n') {
            lines++;
        } else if (c == ' ') {
            blanks++;
        } else if (c == '\t') {
            tabs++;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            words++;
        }
    }

    printf("\nCharacters: %d\n", characters);
    printf("Lines: %d\n", lines);
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Words: %d\n", words);

    return 0;
}