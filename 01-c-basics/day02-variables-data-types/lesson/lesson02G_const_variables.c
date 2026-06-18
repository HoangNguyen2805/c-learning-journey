#include <stdio.h>

int main() {
    const int PASSING_SCORE = 70;
    const int MAX_SCORE = 100;

    int score;

    printf("--- Const Variable Lesson ---\n");

    printf("Enter score: ");
    scanf("%d", &score);

    printf("Max score: %d\n", MAX_SCORE);
    printf("Passing score: %d\n", PASSING_SCORE);

    if (score >= PASSING_SCORE) {
        printf("Result: Pass\n");
    } else {
        printf("Result: Fail\n");
    }

    return 0;
}