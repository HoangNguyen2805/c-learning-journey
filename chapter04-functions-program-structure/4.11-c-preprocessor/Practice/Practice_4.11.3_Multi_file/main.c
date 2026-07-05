#include <stdio.h>
#include "calculator.h"

int main() {
    int num1, num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("add(%d, %d) = %d\n", num1, num2, add(num1, num2));
    printf("subtract(%d, %d) = %d\n", num1, num2, subtract(num1, num2));
    printf("multiply(%d, %d) = %d\n", num1, num2, multiply(num1, num2));
    printf("divide(%d, %d) = %d\n", num1, num2, divide(num1, num2));
    
    printf("max(%d, %d) = %d\n", num1, num2, max(num1, num2));
    printf("min(%d, %d) = %d\n", num1, num2, min(num1, num2));
    printf("square(%d) = %d\n", num1, square(num1));
    printf("square(%d) = %d\n", num2, square(num2));
    
    return 0;
}