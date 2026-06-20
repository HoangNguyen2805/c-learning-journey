#include <stdio.h>

int externalCount;

int main() {
    int age;
    int lower, upper, step;

    int score = 90;
    double price = 9.99;
    char grade = 'A';

    const int MAX_SCORE = 100;
    const double TAX_RATE = 0.0825;

    age = 25;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Age: %d\n", age);
    printf("Lower: %d\n", lower);
    printf("Upper: %d\n", upper);
    printf("Step: %d\n", step);

    printf("Score: %d\n", score);
    printf("Price: %.2f\n", price);
    printf("Grade: %c\n", grade);

    printf("Max score: %d\n", MAX_SCORE);
    printf("Tax rate: %.4f\n", TAX_RATE);

    printf("External count default value: %d\n", externalCount);

    return 0;
}