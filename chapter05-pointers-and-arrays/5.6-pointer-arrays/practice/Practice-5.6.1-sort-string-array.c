/*
Practice 5.6.1 — Sort an Array of Strings

Sort the array below into alphabetic order and print the result. Sort by
rearranging the pointer array. Do not copy any string.

Use selection sort — not quicksort. The point here is the pointer handling,
not the algorithm.

Constraints:
- Write your own swap(char *v[], int i, int j)
- The strings themselves must not move
- Use strcmp for comparison, never <

Verification, and this is the real exercise:
  Print the address of each string before sorting and again after. Every
  address must be unchanged. If any address moved, you copied text somewhere.
  Use printf("%p", (void *)words[i]) to see them.

Hint, not a solution:
  Selection sort: find the smallest remaining element, swap it into position,
  repeat. The only thing that differs from the integer version is how you
  compare two elements.

  Before you write swap, work out what type temp has to be. It is not char,
  and it is not char[]. Look at what one element of words actually is.

DSA concept: comparison sort on an indirect array
Approach: selection sort over the pointer array, strcmp as the comparator
Time: O(n^2) comparisons, O(n) swaps
Space: O(1) extra — no string is duplicated

Expected output order:
  apple banana cherry date elderberry fig grape
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
