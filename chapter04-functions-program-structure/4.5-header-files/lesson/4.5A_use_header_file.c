#include <stdio.h>
#include "math_utils.h"

int main() {
    int sum;
    int product;

    sum = add(10, 20);
    product = multiply(5, 6);

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}