#include <stdio.h>

int main() {
    int number = 255;
    int small = 7;
    double price = 12.5;
    char grade = 'A';
    char name[] = "Hoang";

    printf("--- printf Placeholders ---\n\n");

    // Basic placeholders
    printf("Decimal integer: %d\n", number);
    printf("Octal integer: %o\n", number);
    printf("Hexadecimal integer: %x\n", number);
    printf("Character: %c\n", grade);
    printf("String: %s\n", name);
    printf("Percent sign: 90%%\n");

    printf("\n--- Decimal Formatting ---\n");

    // Decimal places
    printf("Normal double: %f\n", price);
    printf("Two decimal places: %.2f\n", price);
    printf("One decimal place: %.1f\n", price);

    printf("\n--- Field Width ---\n");

    // Width means minimum space used
    printf("Normal int: %d\n", small);
    printf("Width 3 int: %3d\n", small);
    printf("Width 6 int: %6d\n", small);

    printf("\n--- Left Align ---\n");

    // Minus sign means left-align inside the width
    printf("Right aligned: |%6d|\n", small);
    printf("Left aligned:  |%-6d|\n", small);

    printf("\n--- Width With Decimals ---\n");

    // 8 = total width, .2 = two digits after decimal
    printf("Width 8, two decimals: |%8.2f|\n", price);
    printf("Left aligned decimal:  |%-8.2f|\n", price);

    printf("\n--- Zero Padding ---\n");

    // 0 before width means fill empty space with zeros
    printf("Zero padded int: %05d\n", small);

    return 0;
}