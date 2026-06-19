// At this point ,you have NOT leanr about LOOP yet, this is just an example of
//how we can write program in a diffrent way instead of repeatedlly 
// printf, we cand make a loop to generate as many printf as we need.

/*
Practice 1.3 — Celsius to Fahrenheit Table

Create:

chapter01-tutorial-introduction/1.3-the-for-statement/practice/practice01_celsius_fahrenheit_for.c

Task:

Print a Celsius to Fahrenheit table using a for loop.

Use variables:

int lower;
int upper;
int step;
int celsius;
int fahr;

Set:

lower = 0;
upper = 100;
step = 10;

Formula:

fahr = (celsius * 9 / 5) + 32;

Expected output style:

Celsius Fahrenheit
  0       32
 10       50
 20       68
 30       86
 40      104
 50      122
 60      140
 70      158
 80      176
 90      194
100      212

Use:

printf("%3d %8d\n", celsius, fahr);

*/

#include <stdio.h>

int main() {
    int lower;
    int upper;
    int step;
    int celsius;
    int fahr;

    lower = 0;
    upper = 100;
    step = 10;

    printf("Celsius Fahrenheit\n");

    for (celsius = lower; celsius <= upper; celsius = celsius + step) {
        fahr = (celsius * 9 / 5) + 32;
        printf("%3d %8d\n", celsius, fahr);
    }

    return 0;
}