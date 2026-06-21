#include <stdio.h>

#define MAX_SCORE 100
#define PASSING_SCORE 70

int main() {
    int score = 85;

    printf("Max score: %d\n", MAX_SCORE);
    printf("Passing score: %d\n", PASSING_SCORE);
    printf("Student score: %d\n", score);

    if (score >= PASSING_SCORE) {
        printf("Result: Pass\n");
    }
    else {
        printf("Result: Fail\n");
    }

    return 0;
}