#include <stdio.h>

int main() {

    int score;

    printf("Enter score: ");
    scanf("%d", &score);

    printf("Score: %d\n", score);

    if (score >= 90) {            // Above 90, If Not
        printf("Grade: A\n");
    } else if (score >= 80) {     // Above 80, If Not
        printf("Grade: B\n");
    } else if (score >= 70) {     // Above 70, If Not
        printf("Grade: C\n");
    } else {                      // Below 70
        printf("Grade: F\n");
    }

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 05C - else if

else if lets us check more than two possible cases.

Example:

if (score >= 90) {
    printf("Grade: A\n");
} else if (score >= 80) {
    printf("Grade: B\n");
} else if (score >= 70) {
    printf("Grade: C\n");
} else {
    printf("Grade: F\n");
}

C checks from top to bottom.

If one condition is true, C runs that block and skips the rest.

Example:

score = 85

score >= 90 is false
score >= 80 is true

So C prints Grade: B and stops checking.

Important:

Order matters.

Put the highest / most specific condition first.

*/