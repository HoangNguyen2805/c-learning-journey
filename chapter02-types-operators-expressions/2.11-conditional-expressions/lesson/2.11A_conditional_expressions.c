#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int max;
    int min;

    int score = 85;
    int age = 17;

    max = (a > b) ? a : b;
    min = (a < b) ? a : b;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);

    printf("Score: %d\n", score);
    printf("Result: %s\n", score >= 70 ? "Pass" : "Fail");

    printf("Age: %d\n", age);
    printf("Adult status: %s\n", age >= 18 ? "Adult" : "Not adult");

    printf("Is a greater than b? %d\n", a > b ? 1 : 0);
    printf("Is b greater than a? %d\n", b > a ? 1 : 0);

    return 0;
}