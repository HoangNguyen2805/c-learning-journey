/*
Practice 01 - Data Types, Sizes, and Limits

Goal:
Practice the main ideas from K&R 2.2.

Requirements:

1. Include the needed headers:

   * stdio.h
   * stdbool.h
   * limits.h
   * float.h

2. Create variables for these types:

   * char
   * char[]
   * int
   * short
   * long
   * signed int
   * unsigned int
   * float
   * double
   * bool

3. Print each variable with the correct printf placeholder.

4. Print the size in bytes of:

   * char
   * short
   * int
   * long
   * float
   * double

5. Print integer information from limits.h:

   * CHAR_BIT
   * SCHAR_MIN
   * SCHAR_MAX
   * UCHAR_MAX
   * INT_MIN
   * INT_MAX
   * UINT_MAX

6. Print floating-point information from float.h:

   * FLT_MAX
   * DBL_MAX
   * FLT_DIG
   * DBL_DIG

7. Show unsigned wraparound:

   * Create an unsigned char with the maximum value.
   * Add 1 to it.
   * Print the result.

8. Add comments explaining:

   * signed
   * unsigned
   * sizeof
   * why unsigned values wrap around

Do not copy from the lesson file.
Try to write it from memory first.
*/
// SOLVE here

#include <stdio.h>




/* EXAMPLE DONT LOOK UNTIL COMPLETE
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

int main() {
    char grade = 'A';
    char name[] = "Hoang";

    int age = 25;
    short smallNumber = 100;
    long bigNumber = 8000000L;

    signed int temperature = -10;
    unsigned int count = 50;

    float price = 9.99f;
    double pi = 3.1415926535;

    bool isStudent = true;

    unsigned char maxUnsignedChar = UCHAR_MAX;

    printf("Basic values:\n");
    printf("Name: %s\n", name);
    printf("Grade: %c\n", grade);
    printf("Age: %d\n", age);
    printf("Small number: %hd\n", smallNumber);
    printf("Big number: %ld\n", bigNumber);
    printf("Temperature: %d\n", temperature);
    printf("Count: %u\n", count);
    printf("Price: %.2f\n", price);
    printf("Pi: %.10f\n", pi);
    printf("Is student: %d\n", isStudent);

    printf("\nSizes in bytes:\n");
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));

    printf("\nBits and ranges:\n");
    printf("CHAR_BIT: %d\n", CHAR_BIT);
    printf("signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char range: 0 to %u\n", UCHAR_MAX);
    printf("int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);

    printf("\nUnsigned wraparound:\n");
    printf("Before: %u\n", maxUnsignedChar);
    maxUnsignedChar = maxUnsignedChar + 1;
    printf("After adding 1: %u\n", maxUnsignedChar);

    printf("\nFloat limits:\n");
    printf("float max: %e\n", FLT_MAX);
    printf("double max: %e\n", DBL_MAX);
    printf("float digits: %d\n", FLT_DIG);
    printf("double digits: %d\n", DBL_DIG);

    return 0;
}

*/