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

/*
## Lesson 06E - continue

continue skips the current loop round and moves to the next round.

Example:

for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue;
    }

    printf("%d\n", i);
}

Output:

1
2
4
5

When i is 3, continue skips printf.
The loop does not stop.
It just moves to the next round.

Memory rule:

break = stop the whole loop
continue = skip this round only

*/