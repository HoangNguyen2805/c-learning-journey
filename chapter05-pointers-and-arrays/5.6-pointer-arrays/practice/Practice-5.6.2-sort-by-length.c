/*
Practice 5.6.2 — Sort by a Different Criterion

Same array as 5.6.1, but sort by string length, shortest first. Ties broken
alphabetically.

Then produce both orderings in one run — length order, then alphabetical —
without writing the sort twice.

Constraints:
- One sort function, called twice
- No copying of string data
- Ties in length resolved with strcmp

Hint, not a solution:
  A sorting algorithm does not care what "comes before" means. It only asks a
  question and acts on the answer. If that question is hard-coded inside the
  sort, you need two sorts. If it is not, you need one.

  The straightforward move at this stage is an extra parameter — a flag the
  sort consults when comparing. Do that first. It works and it is honest code.

  Then, if you want to reach ahead: K&R develops the better answer in 5.11 by
  passing the comparison function itself. The parameter you would need is

      int (*comp)(char *, char *)

  Write it the flag way, then the function-pointer way, and notice which one
  you would rather extend to a third ordering.

DSA concept: separating ordering policy from sorting mechanism
Approach: parameterized comparison
Time: O(n^2) with selection sort, unchanged by which comparison is used
Space: O(1)

Expected length order (ties alphabetical):
  fig date apple grape banana cherry elderberry

Follow-up: add a third ordering — by last character. How many lines of your
program have to change? That number is the answer to whether you factored the
comparison out properly.
*/

#include <stdio.h>
#include <string.h>

void swap(char *v[], int i, int j);

int main()
{
    char *words[7];

    words[0] = "banana";
    words[1] = "apple";
    words[2] = "cherry";
    words[3] = "date";
    words[4] = "elderberry";
    words[5] = "fig";
    words[6] = "grape";

    return 0;
}
