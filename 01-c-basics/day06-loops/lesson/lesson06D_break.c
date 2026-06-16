#include <stdio.h>

int main() {

    printf("--- Break Example ---\n");

    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break;
        }

        printf("%d\n", i);
    }

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 06D - break

break stops the loop immediately.

Example:

for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;
    }

    printf("%d\n", i);
}

Output:

1
2
3
4

When i becomes 5, break runs and the loop stops before printing 5.

Memory rule:

break = stop the whole loop now

*/