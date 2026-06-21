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
#include <stdbool.h>
#include <limits.h>
#include <float.h>

int main() {

   char letter = 'A';
   printf("Letter: %c\n", letter);
   char name[50] = "Hoang";
   printf("Name: %s\n", name);

   short smallNumber = 32767; // -32767 to 32767
   printf("Small number: %d\n", smallNumber);
   int normalNumber = 2147483647; // -2,147,483,648 to 2,147,483,647
   printf("Normal number: %d\n", normalNumber);
   long bigNumber = 9223372036854775807L; //-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
   printf("Big number: %ld\n", bigNumber);
   signed int negNumber = -100;
   printf("Can be negative, zero or positive: %d\n", negNumber);
   unsigned int stillNegnumber = 1000; // if unsigned int variable = - negative number -> it will compile some random error value, it's not absolute value | x |
   printf("Can't be negative: %u\n", stillNegnumber);
   float decimalNumber = 0.1234567; // ±1.175494e-38 to ±3.402823e+38 , 6 to 7 decimal digits precision
   printf("Number with decimal: %.7f\n", decimalNumber);
   double moreprecisionDecimalnumber = 0.123456789101112;  // ±2.225074e-308 to ±1.797693e+308 , about 15 to 16 decimal digits precision
   printf("More specific number with decimal: %.16f\n", moreprecisionDecimalnumber); // %lf for double in scanf input
   bool richPoor = true; // True = non-zero
   bool poorRich = false;// False = 0
   printf("Hoang is rich -> %d\n", richPoor);
   printf("Hoang is poor -> %d\n", poorRich);
   bool tall = 1; // True = non-zero
   bool hshort = 0;// False = 0
   printf("Hoang is tall -> %d\n", tall);
   printf("Hoang is short -> %d\n", hshort);

   // print size of data type = sizeof(data type)
   // placeholder = %zu
   printf("\nSize of char: %zu bytes\n", sizeof(char));
   printf("Size of short: %zu bytes\n", sizeof(short));
   printf("Size of int: %zu bytes\n", sizeof(int));
   printf("Size of long: %zu bytes\n", sizeof(long));
   printf("Size of float: %zu bytes\n", sizeof(float));
   printf("Size of double: %zu bytes\n", sizeof(double));

   // If you have more than one int, you can use variable to be more specifc.

   printf("\nSize of char: %zu bytes\n", sizeof(letter));
   printf("Size of short: %zu bytes\n", sizeof(smallNumber));
   printf("Size of int: %zu bytes\n", sizeof(normalNumber));
   printf("Size of long: %zu bytes\n", sizeof(bigNumber));
   printf("Size of float: %zu bytes\n", sizeof(decimalNumber));
   printf("Size of double: %zu bytes\n", sizeof(moreprecisionDecimalnumber));

   // Form <limits.h> , use 
   // #include <limits.h>   // integer limits
   
   // Number of bits in one char. Usually 8.
   printf("\nCHAR_BIT: %d\n", CHAR_BIT);
   // Smallest value for signed char. Usually -128.
   printf("SCHAR_MIN: %d\n", SCHAR_MIN);
   // Largest value for signed char. Usually 127.
   printf("SCHAR_MAX: %d\n", SCHAR_MAX);
   // Largest value for unsigned char. Usually 255.
   printf("UCHAR_MAX: %u\n", UCHAR_MAX);
   // Smallest value for int. Usually -2147483648.
   printf("INT_MIN: %d\n", INT_MIN);
   // Largest value for int. Usually 2147483647.
   printf("INT_MAX: %d\n", INT_MAX);
   // Largest value for unsigned int. Usually 4294967295.
   printf("UINT_MAX: %u\n", UINT_MAX);

   // From <float.h> , use
   // #include <float.h>    // float/double limits

   // Largest positive float value. Around 3.402823e+38.
   printf("FLT_MAX: %e\n", FLT_MAX);
   // Largest positive double value. Around 1.797693e+308.
   printf("DBL_MAX: %e\n", DBL_MAX);
   // How many decimal digits a float can accurately store. Usually 6.
   printf("FLT_DIG: %d\n", FLT_DIG);
   // How many decimal digits a double can accurately store. Usually 15.
   printf("DBL_DIG: %d\n", DBL_DIG);

   // This also work but not recomend
   int charBits = CHAR_BIT;
   printf("\nBits in one char: %d\n", charBits);

   // Show unsigned wraparound.
   // UCHAR_MAX is usually 255.
   // When unsigned char goes past 255, it wraps back to 0.
   unsigned char maxNumber = UCHAR_MAX;

   maxNumber = maxNumber + 1;

   printf("\nUnsigned char max + 1: %u\n", (unsigned int) maxNumber);

   // signed:
   // A signed integer can store negative numbers, zero, and positive numbers.
   // Example: signed int can hold values like -100, 0, and 100.

   // unsigned:
   // An unsigned integer cannot store negative numbers.
   // It can only store zero and positive numbers.
   // Example: unsigned int can hold values like 0, 100, and 1000.

   // sizeof:
   // sizeof tells how many bytes a data type or variable uses in memory.
   // Example: sizeof(int) shows how many bytes an int uses.

   // unsigned wraparound:
   // Unsigned values wrap around when they go past their maximum value.
   // For example, unsigned char usually goes from 0 to 255.
   // If unsigned char is 255 and you add 1, it wraps back to 0.

   return 0;
}



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