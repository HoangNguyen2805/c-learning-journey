#include <stdio.h>

int main() {

    printf("--- For Loop ---\n");

    for (int i = 1; i <= 5; i++) { // ( start at int i = 1 ; run as long as i less than or equal to 5 , if it more than 5 stop ; update each loop by increment of 1)
        printf("%d\n", i);
    }

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 06B - for loop

A for loop repeats code using start, condition, and update in one line.

Format:

for (start; condition; update) {
    code;
}

Example:

for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}

Parts:

int i = 1 means start at 1.
i <= 5 means keep looping while i is 5 or less.
i++ means add 1 after each loop.

The loop prints:

1
2
3
4
5

A for loop is good when I know how many times I want to repeat.

*/