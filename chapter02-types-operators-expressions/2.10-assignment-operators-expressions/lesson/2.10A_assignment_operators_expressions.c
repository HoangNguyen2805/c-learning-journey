#include <stdio.h>

int main() {
    int x = 10;
    int y;
    int a;
    int b;
    int c;

    unsigned int bits = 0x0F;
    unsigned int mask = 0x03;

    printf("Basic assignment:\n");
    printf("Starting x = %d\n", x);

    x = 20;
    printf("After x = 20: %d\n", x);

    printf("\nAssignment expression:\n");
    y = (x = 5);
    printf("After y = (x = 5):\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("\nChained assignment:\n");
    a = b = c = 0;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    printf("\nCompound assignment:\n");
    x = 20;
    printf("Start x = %d\n", x);

    x += 5;
    printf("After x += 5: %d\n", x);

    x -= 10;
    printf("After x -= 10: %d\n", x);

    x *= 2;
    printf("After x *= 2: %d\n", x);

    x /= 3;
    printf("After x /= 3: %d\n", x);

    x %= 4;
    printf("After x %%= 4: %d\n", x);

    printf("\nGrouping rule:\n");
    x = 2;
    y = 3;
    x *= y + 1;
    printf("x = 2, y = 3, after x *= y + 1: %d\n", x);

    printf("\nBitwise assignment:\n");
    printf("bits = 0x%x\n", bits);
    printf("mask = 0x%x\n", mask);

    bits &= mask;
    printf("After bits &= mask: 0x%x\n", bits);

    bits |= mask;
    printf("After bits |= mask: 0x%x\n", bits);

    bits ^= mask;
    printf("After bits ^= mask: 0x%x\n", bits);

    bits <<= 1;
    printf("After bits <<= 1: 0x%x\n", bits);

    bits >>= 1;
    printf("After bits >>= 1: 0x%x\n", bits);

    return 0;
}