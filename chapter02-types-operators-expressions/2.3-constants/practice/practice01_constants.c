/*
Practice 01 - Constants

Goal:
Practice the main ideas from K&R 2.3 Constants.

Requirements:

1. Include stdio.h.

2. Create and print integer constants:

   * decimal
   * octal
   * hexadecimal

3. Create and print integer constants with suffixes:

   * long using L
   * unsigned using U
   * unsigned long using UL

4. Create and print floating-point constants:

   * normal decimal form
   * scientific notation

5. Create and print character constants:

   * normal character
   * newline escape
   * tab escape
   * alert / bell escape
   * vertical tab escape
   * backslash escape
   * double quote escape
   * single quote escape

6. Create and print a string constant.

7. Create symbolic constants using #define:

   * one integer symbolic constant
   * one character symbolic constant
   * one string symbolic constant

8. Create enum constants:

   * one enum that starts at 0 automatically
   * one enum where the first value is set manually

9. Add comments explaining:

   * decimal constant
   * octal constant
   * hexadecimal constant
   * character constant
   * string constant
   * escape sequence
   * symbolic constant
   * enum constant

Rules:

* Do not use loops.
* Do not use if/else.
* Do not copy the lesson file exactly.
* Write it from memory first, then check your notes.
  */

  #include <stdio.h>

   // 7.
   #define INTEGER_SYMBOLIC 1000
   #define CHARACTER_SYMBOLIC 'B'
   #define STRING_SYMBOLIC "HELLO"

   // 8.
   enum Day{
      SUNDAY , MONDAY , TUESDAY , WEDNESDAY , THURSDAY , FRIDAY , SATURDAY
   };//    0        1         2           3          4        5          6

   enum Night{
      SUNDA_Y = 1 , MONDA_Y = 2 , TUESDA_Y = 3 , WEDNESDA_Y = 4 , THURSDA_Y = 5 , FRIDA_Y = 6 , SATURDA_Y = 7
   };

  int main() {

   // 2
   int decimalNumber = 31;   // decimal
   printf("Decimal: %d\n", decimalNumber);
   int octalNumber = 037;    // octal, starts with 0
   printf("Octal: %d\n", octalNumber);
   int hexNumber = 0x1F;     // hexadecimal, starts with 0x
   printf("hex: %d\n", hexNumber);

   // 3.
   long bigNumber = 12345678910111213L;
   printf("\nLong big whole number: %ld\n", bigNumber);
   unsigned posNumber = 1234567U;
   printf("Non-negative number: %u\n", posNumber);
   unsigned long posBignumber = 12345678910111213UL;
   printf("Non-negative , long number: %lu\n", posBignumber);

   // 4.
   float normalFloat = 3.14;
   printf("\nNormal decimal number: %.2f\n", normalFloat);
   double bigScientific = 3.402823e+38;
   printf("Big Scientific notation: %e\n", bigScientific);
   double smallScientific = 0.00000123;
   printf("Small Scientific notation: %e\n", smallScientific);

   // 5.
   char singleCharacter = 'A';
   printf("\nSingle character: %c\n", singleCharacter);
   char newline = '\n';
   printf("New line escape: [%c]\n", newline);
   char tab = '\t';
   printf("Tab escape: [%c]\n", tab);
   char alert = '\a';
   printf("Alert / bell escape: [%c]\n", alert);
   char vertical = '\v';
   printf("Vertical tab escape: [%c]\n", vertical);
   char backslash = '\\';
   printf("Backslash escape: [%c]\n", backslash);
   char doubleQuote = '\"';
   printf("Double quote escape: [%c]\n", doubleQuote);
   char singleQuote = '\'';
   printf("Single quote escape: [%c]\n", singleQuote);

   // 6.
   char string[50] = "Hoang";
   printf("\nString: %s\n", string);

   // 7.
   printf("\nINTEGER_SYMBOLIC: %d\n", INTEGER_SYMBOLIC);
   printf("CHARACTER_SYMBOLIC: %c\n", CHARACTER_SYMBOLIC);
   printf("STRING_SYMBOLIC: %s\n", STRING_SYMBOLIC);

   // 8.
   enum Day morning = TUESDAY;

      printf("\nAutomatic enum TUESDAY value: %d\n", morning);

   enum Night night = TUESDA_Y;

    printf("Manual enum TUESDA_Y value: %d\n", night);

   // 9.

   /*
   ```c
// Decimal constant: a normal base-10 number using digits 0-9.
int decimalNumber = 31;

// Octal constant: a base-8 number that starts with 0 and uses digits 0-7.
int octalNumber = 037;

// Hexadecimal constant: a base-16 number that starts with 0x and uses digits 0-9 and A-F.
int hexNumber = 0x1F;

// Character constant: one character inside single quotes.
char singleCharacter = 'A';

// Escape sequence: special character written with backslash, like '\n', '\t', or '\\'.
char newline = '\n';

// String constant: text inside double quotes, automatically ending with '\0'.
char string[50] = "Hoang";

// Symbolic constant: a name created with #define that stands for a fixed value.
#define INTEGER_SYMBOLIC 1000
#define CHARACTER_SYMBOLIC 'B'
#define STRING_SYMBOLIC "HELLO"

// Enum constant: a named integer value inside an enum.
enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

// Enum with first value set manually.
// After SUNDA_Y = 1, C keeps counting up by 1.
enum ManualDay {
    SUNDA_Y = 1,
    MONDA_Y,
    TUESDA_Y,
    WEDNESDA_Y,
    THURSDA_Y,
    FRIDA_Y,
    SATURDA_Y
};
```

   
   */

   return 0;
  }