#include <stdio.h>

int addNumbers(int a, int b);

int main() {
    int x = 5;
    int y = 3;
    int result;

    result = addNumbers(x, y);

    printf("x in main: %d\n", x);
    printf("y in main: %d\n", y);
    printf("Result: %d\n", result);

    return 0;
}

int addNumbers(int a, int b) {
    int total = a + b;

    printf("a inside function: %d\n", a);
    printf("b inside function: %d\n", b);
    printf("total inside function: %d\n", total);

    return total;
}