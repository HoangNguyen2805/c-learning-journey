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