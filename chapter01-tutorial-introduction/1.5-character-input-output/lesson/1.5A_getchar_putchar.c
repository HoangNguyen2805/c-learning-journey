#include <stdio.h>

int main() {
    int c;

    printf("Enter one character: ");

    c = getchar();

    printf("You entered: ");
    putchar(c);
    printf("\n");

    return 0;
}