#include <stdio.h>

int main() {
    unsigned int x = 0x0F;
    unsigned int y = 0x33;
    unsigned int mask = 0x0F;

    printf("Starting values:\n");
    printf("x = 0x%x\n", x);
    printf("y = 0x%x\n", y);
    printf("mask = 0x%x\n", mask);

    printf("\nBitwise AND:\n");
    printf("x & y = 0x%x\n", x & y);

    printf("\nBitwise OR:\n");
    printf("x | y = 0x%x\n", x | y);

    printf("\nBitwise exclusive OR:\n");
    printf("x ^ y = 0x%x\n", x ^ y);

    printf("\nBitwise complement:\n");
    printf("~x = 0x%x\n", ~x);

    printf("\nLeft shift:\n");
    printf("x << 1 = 0x%x\n", x << 1);

    printf("\nRight shift:\n");
    printf("x >> 1 = 0x%x\n", x >> 1);

    printf("\nMask examples:\n");
    printf("x & mask = 0x%x\n", x & mask);
    printf("x | mask = 0x%x\n", x | mask);
    printf("x & ~mask = 0x%x\n", x & ~mask);
    printf("x ^ mask = 0x%x\n", x ^ mask);

    return 0;
}