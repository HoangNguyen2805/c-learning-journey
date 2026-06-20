#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Sizes in bytes:\n");
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));

    printf("\nBits:\n");
    printf("char bits: %d\n", CHAR_BIT);
    printf("int bits: %zu\n", sizeof(int) * CHAR_BIT);

    printf("\nInteger limits:\n");
    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
    printf("unsigned char max: %u\n", UCHAR_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);

    printf("\nFloating-point limits:\n");
    printf("float max: %e\n", FLT_MAX);
    printf("double max: %e\n", DBL_MAX);
    printf("float digits: %d\n", FLT_DIG);
    printf("double digits: %d\n", DBL_DIG);

    return 0;
}