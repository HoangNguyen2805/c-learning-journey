#include <stdio.h>

int main(){
    int a = 10;
    int b = 3;

    printf("--- Modulus / Remainder ---\n");

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("\nDivision:\n");
    printf("%d / %d = %d\n", a, b, a / b);

    printf("\nRemainder:\n");
    printf("%d %% %d = %d\n", a, b, a % b);

    printf("\nMore examples:\n");
    printf("10 %% 2 = %d\n", 10 % 2);
    printf("10 %% 3 = %d\n", 10 % 3);
    printf("10 %% 4 = %d\n", 10 % 4);
    printf("10 %% 5 = %d\n", 10 % 5);

    printf("\nEven or odd idea:\n");
    printf("10 %% 2 = %d\n", 10 % 2);
    printf("11 %% 2 = %d\n", 11 % 2);

    return 0;
}