#include <stdio.h>

int main() {

    int i = 1;

    printf("--- Do While Loop ---\n");

    do {
        printf("%d\n", i);
        i++;
    } while (i <= 5);

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 06C - do while loop

A do while loop runs the code first, then checks the condition.

Format:

do {
    code;
} while (condition);

Example:

int i = 1;

do {
    printf("%d\n", i);
    i++;
} while (i <= 5);

Output:

1
2
3
4
5

Important:

A do while loop always runs at least one time.

while loop = check first, then run
do while loop = run first, then check

*/