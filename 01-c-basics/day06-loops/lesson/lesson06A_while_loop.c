#include <stdio.h>

int main() {
                                // While loop consist of 3 part:
    int i = 1;                  // 1. Start value. The loop start at int i = 1;

    printf("--- While Loop ---\n");

    while (i <= 5) {            // 2. Condition. The loop will not stop as long as i <= 5
        printf("%d\n", i);      //           -> each time looping, it print i value.
        i++;                    // 3. Update. i value will update each loop by increment of 1
    }

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 06A - while loop

A while loop repeats code while a condition is true.

Example:

int i = 1;

while (i <= 5) {
    printf("%d\n", i);
    i++;
}

Parts:

int i = 1 means start value.
i <= 5 means condition.
i++ means update.

The loop steps:

i = 1, print 1, then i becomes 2
i = 2, print 2, then i becomes 3
i = 3, print 3, then i becomes 4
i = 4, print 4, then i becomes 5
i = 5, print 5, then i becomes 6
i = 6, condition is false, stop.

Important:

If i never changes, the loop can become an infinite loop.

Example of bad loop:

int i = 1;

while (i <= 5) {
    printf("%d\n", i);
}

This prints 1 forever because i never increases.

*/