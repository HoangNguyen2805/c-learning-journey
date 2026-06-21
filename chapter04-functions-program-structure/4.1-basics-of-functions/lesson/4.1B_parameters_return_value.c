#include <stdio.h>

int square(int x);
int add(int a, int b);

int main() {
    int number = 5;
    int result;
    int sum;

    result = square(number);
    sum = add(10, 20);

    printf("number = %d\n", number);
    printf("square(number) = %d\n", result);
    printf("add(10, 20) = %d\n", sum);

    return 0;
}

int square(int x) {
    return x * x;
}

int add(int a, int b) {
    return a + b;
}