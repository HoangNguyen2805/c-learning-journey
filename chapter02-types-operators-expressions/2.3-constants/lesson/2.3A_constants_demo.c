#include <stdio.h>

#define MAX_SCORE 100
#define PASSING_SCORE 70
#define NEWLINE '\n'

enum boolean {
    NO,
    YES
};

int main() {
    int decimalNumber = 31;
    int octalNumber = 037;
    int hexNumber = 0x1F;

    long longNumber = 123456L;
    unsigned int unsignedNumber = 100U;
    unsigned long unsignedLongNumber = 100UL;

    double normalFloat = 3.14;
    double scientificFloat = 1.5e3;

    char grade = 'A';
    char tab = '\t';
    char newline = '\n';

    char name[] = "Hoang";

    printf("Decimal constant: %d\n", decimalNumber);
    printf("Octal constant 037 as decimal: %d\n", octalNumber);
    printf("Hex constant 0x1F as decimal: %d\n", hexNumber);

    printf("Long constant: %ld\n", longNumber);
    printf("Unsigned constant: %u\n", unsignedNumber);
    printf("Unsigned long constant: %lu\n", unsignedLongNumber);

    printf("Normal floating constant: %.2f\n", normalFloat);
    printf("Scientific floating constant: %.2f\n", scientificFloat);

    printf("Character constant: %c\n", grade);
    printf("String constant: %s\n", name);

    printf("Tab escape:%cAfter tab\n", tab);
    printf("Newline escape:%cAfter newline\n", newline);

    printf("Symbolic constant MAX_SCORE: %d\n", MAX_SCORE);
    printf("Symbolic constant PASSING_SCORE: %d\n", PASSING_SCORE);

    printf("Enum NO: %d\n", NO);
    printf("Enum YES: %d\n", YES);

    printf("Symbolic character constant NEWLINE:%cDone\n", NEWLINE);

    return 0;
}