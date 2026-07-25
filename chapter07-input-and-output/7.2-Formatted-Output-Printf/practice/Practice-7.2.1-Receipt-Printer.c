/*
Practice 7.2.1 - Receipt Printer (format mastery)

Problem:
Given hardcoded data, print a PERFECTLY aligned store receipt:

  struct item { char *name; double price; int qty; };
  struct item cart[] = {
      {"espresso", 3.5, 2}, {"blueberry muffin", 4.25, 1},
      {"orange juice", 2.0, 3}, {"bagel", 1.75, 2}
  };

Target output (columns must line up EXACTLY; name column 18 wide
truncated with precision, money right-aligned width 8, qty width 3):

  ================================
  ITEM               QTY    TOTAL
  ================================
  espresso             2     7.00
  blueberry muffin     1     4.25
  ...
  --------------------------------
  SUBTOTAL                  ??.??
  TAX (8.25%)                ?.??
  TOTAL                     ??.??

Requirements:
- One printf per line; widths/precisions in the format string, not spaces
  you counted by hand in the data.
- Long names must be TRUNCATED by precision (test by adding a 25-char item).
- Total per line = price*qty; accumulate subtotal in the same loop.
- Print the separator rows using %.*s trick over a long "=====" constant
  OR a loop - your choice; justify in a comment.

DSA/Algorithm Focus: none new - this is precision formatting drill + fold
Best approach: single O(n) pass computing and printing simultaneously.
Complexity: O(n) time, O(1) space.
Constraints: every money value via ONE consistent %8.2f spec; NITEMS by sizeof.

Hints (Socratic):
- Which spec truncates a too-long name: %18s or %.18s or %-18.18s? Why the third?
- Why does money as double + %.2f *display* fine here yet real POS systems
  store cents in integers? (One-line comment.)
- What field width does "TAX (8.25%)" need so its amount aligns with the others?
*/

#include <stdio.h>

struct item {
    char *name;
    double price;
    int qty;
};

int main(){
    // Student writes code here
    return 0;
}
