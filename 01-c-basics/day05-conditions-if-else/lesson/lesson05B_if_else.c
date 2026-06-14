#include <stdio.h>

int main() {

    int age;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Age: %d\n", age);

    if (age >= 18) {                        // TRUE , age is above 18
        printf("You can vote.\n");
    } else {                                // FALSE , age is below 18
        printf("You cannot vote yet.\n");
    }

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 05B - if / else

if / else lets the program choose between two paths.

Example:

if (age >= 18) {
    printf("You can vote.\n");
} else {
    printf("You cannot vote yet.\n");
}

If age is 18 or older, the if block runs.

If age is below 18, the else block runs.

Only one block runs:
- if block OR
- else block

Code after the if / else still runs normally.
*/