/*
Practice 5.8.3 — Integer to Roman Numerals with Place-Value Tables

Convert 1..3999 to a Roman numeral string using FOUR static pointer
arrays — one for each decimal place:

    ones[]      = { "", "I", "II", "III", "IV", "V", ... "IX" }
    tens[]      = { "", "X", "XX", ... "XC" }
    hundreds[]  = { "", "C", "CC", ... "CM" }
    thousands[] = { "", "M", "MM", "MMM" }

Index = that digit. 1994 -> thousands[1] hundreds[9] tens[9] ones[4]
                          =  "M"          "CM"        "XC"    "IV"
                          =  "MCMXCIV"

Write:
  char *append(char *dst, char *src);
        copy src onto dst; return a pointer to the new '\0' in dst
        (pointer arithmetic, no strcat/strcpy)
  int   to_roman(int n, char *out);
        fill out with the numeral; return 0 on success,
        -1 if n is outside 1..3999 (leave out as "")

Rules:
  - Extract digits with / and %, then index the tables.
  - Chain append calls by reusing its return value — that's why it
    returns a pointer and not void.
  - out buffer lives in main. Work out its minimum safe size and
    justify it in a comment (longest numeral under 4000 + '\0').

Test with: 1, 4, 9, 14, 40, 90, 400, 1994, 2024, 3888, 3999, 0, 4000, -5
Print:   1994 -> MCMXCIV

Questions to answer before coding (write them as comments):
  1. Why does each table start with "" at index 0?
  2. append returns where '\0' landed. Why is that faster than
     calling strlen on out before every copy?
  3. Which input gives the longest numeral? How long is it?

DSA:        Table-driven lookup (decomposition by place value)
Best way:   4 digit extractions + 4 table lookups + 4 appends
Complexity: O(1) time (fixed 4 places, output <= 15 chars),
            O(1) extra space
*/

#include <stdio.h>

char *append(char *dst, char *src);
int   to_roman(int n, char *out);

int main()
{
    // Student writes code here
    return 0;
}
