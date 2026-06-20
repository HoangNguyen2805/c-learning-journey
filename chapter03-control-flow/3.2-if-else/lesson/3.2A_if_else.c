#include <stdio.h>

int main() {
    int score = 85;
    int age = 17;
    int hasID = 1;

    printf("If statement:\n");

    if (score >= 70)
        printf("Score is passing.\n");

    printf("\nIf-else statement:\n");

    if (age >= 18)
        printf("Adult\n");
    else
        printf("Not adult\n");

    printf("\nIf-else with braces:\n");

    if (score >= 70) {
        printf("Pass\n");
        printf("Good job\n");
    }
    else {
        printf("Fail\n");
        printf("Try again\n");
    }

    printf("\nNested if:\n");

    if (age >= 16) {
        if (hasID)
            printf("Old enough and has ID\n");
        else
            printf("Old enough but no ID\n");
    }
    else {
        printf("Too young\n");
    }

    return 0;
}