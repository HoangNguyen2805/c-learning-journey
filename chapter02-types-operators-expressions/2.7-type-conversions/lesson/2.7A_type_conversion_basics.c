#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;

    double mixedResult = a + 3.5;
    double integerDivision = a / b;
    double decimalDivision = (double) a / b;

    char digitChar = '7';
    int digitValue = digitChar - '0';

    char letter = 'A';
    int letterCode = letter;

    double price = 9.99;
    int dollars = price;

    printf("Automatic conversion:\n");
    printf("10 + 3.5 = %.2f\n", mixedResult);

    printf("\nInteger division:\n");
    printf("10 / 3 = %.2f\n", integerDivision);

    printf("\nDecimal division using cast:\n");
    printf("(double) 10 / 3 = %.2f\n", decimalDivision);

    printf("\nCharacter to integer conversion:\n");
    printf("'7' - '0' = %d\n", digitValue);
    printf("'A' as integer code = %d\n", letterCode);

    printf("\nAssignment conversion:\n");
    printf("price = %.2f\n", price);
    printf("dollars = %d\n", dollars);

    return 0;
}