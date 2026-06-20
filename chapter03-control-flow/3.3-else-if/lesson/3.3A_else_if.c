#include <stdio.h>

int main() {
    int score = 85;
    int temperature = 72;

    printf("Grade example:\n");

    if (score >= 90)
        printf("Grade: A\n");
    else if (score >= 80)
        printf("Grade: B\n");
    else if (score >= 70)
        printf("Grade: C\n");
    else
        printf("Grade: Fail\n");

    printf("\nTemperature example:\n");

    if (temperature >= 90)
        printf("Hot\n");
    else if (temperature >= 70)
        printf("Warm\n");
    else if (temperature >= 50)
        printf("Cool\n");
    else
        printf("Cold\n");

    printf("\nOrder matters:\n");

    if (score >= 70)
        printf("This runs first because score is at least 70.\n");
    else if (score >= 80)
        printf("This will not run.\n");
    else if (score >= 90)
        printf("This will not run.\n");

    return 0;
}