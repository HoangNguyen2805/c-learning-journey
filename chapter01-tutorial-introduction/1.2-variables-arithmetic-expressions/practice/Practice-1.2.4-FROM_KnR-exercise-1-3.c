/*
[FROM K&R] Exercise 1-3

Book text:
  "Modify the temperature conversion program to print a heading above the
  table."

Start from the floating-point version in section 1.2, the one using
%3.0f and %6.1f. Add a heading above the table.

The exercise is one line long and the interesting part is getting it to line
up. Your column headings should sit over their columns, not near them.

Hint, not a solution:
  The table rows are printed with a known field width. Your heading is a
  string. Look up what %s does with a width the same way %d does — the
  conversion table in the lesson lists %s but not what widths do to it.
  Try it and find out.

  If you would rather not use %s, you can still align by hand with spaces.
  Do it that way first if you like, then change one field width in the table
  and watch your heading fall out of alignment. That is the argument for
  doing it the other way.

Concept: output formatting, field widths
Complexity: not meaningful here — this is a formatting exercise
*/

#include <stdio.h>

int main()
{

    return 0;
}
