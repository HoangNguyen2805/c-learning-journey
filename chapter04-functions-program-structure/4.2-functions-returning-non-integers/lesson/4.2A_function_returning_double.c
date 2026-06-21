#include <stdio.h>

double average(double a, double b);
double celsiusToFahrenheit(double celsius);
double half(int x);

int main() {
    double avg;
    double fahrenheit;
    double result;

    avg = average(85.5, 92.0);
    fahrenheit = celsiusToFahrenheit(25.0);
    result = half(7);

    printf("Average: %.2f\n", avg);
    printf("25 Celsius in Fahrenheit: %.2f\n", fahrenheit);
    printf("Half of 7: %.2f\n", result);

    return 0;
}

double average(double a, double b) {
    return (a + b) / 2.0;
}

double celsiusToFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

double half(int x) {
    return x / 2.0;
}