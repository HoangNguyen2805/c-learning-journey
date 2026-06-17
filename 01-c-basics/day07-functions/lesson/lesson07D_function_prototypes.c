#include <stdio.h>

int addNumbers(int a, int b);
double calculateAverage(int total);
void printMessage();

int main() {
    int total;
    double average;

    printMessage();

    total = addNumbers(80, 90);
    average = calculateAverage(total);

    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);

    return 0;
}

int addNumbers(int a, int b) {
    return a + b;
}

double calculateAverage(int total) {
    return total / 2.0;
}

void printMessage() {
    printf("--- Function Prototype Lesson ---\n");
}