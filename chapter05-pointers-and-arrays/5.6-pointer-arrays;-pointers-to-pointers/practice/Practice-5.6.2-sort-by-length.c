/*
Practice 5.6.2 — Sort by a Different Criterion

Same array as 5.6.1, but sort by string length, shortest first. Ties broken
alphabetically.

              Practice 5.6.1 — Sort an Array of Strings

              Sort the array below into alphabetic order and print the result. Sort by
              rearranging the pointer array. Do not copy any string.

              Use selection sort — not quicksort. The point here is the pointer handling,
              not the algorithm.

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
/*Given:
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
*/

// Structure 1 — two separate sorts (what you just proposed) Not very efficient for complexity.


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
/* 
To sort the length of the string, short first, long later, we need 
- A function sorting the string length

If string length is equal to each other then, sort those string by order of alphabet,
a have value of number that is smaller than z, a is smallest in value and the value go up a long the alphabet. So we need
- A function sorting by comparing character by character.

Both function need take two pointer and move it left right by the result,
To move pointer we need
- A swap function to swap place of the pointer base on result of the other 2 function.

Basically string length function and alphabet function will call swap when it done sorting. swap call within the 2 function.

main ──> sort_alpha ──> swap
     └─> sort_length ──> swap

*/












// Structure 2 — one sort, flag parameter (Option A)

/*
Option A — inline, right there in the `if`. An `if/else` inside the inner loop 
picking which comparison to run.
```c
void sort(char *v[], int n, int mode);
void swap(char *v[], int i, int j);

main:
    sort(words, 7, 0);   // 0 = alpha 
    print
    sort(words, 7, 1);   // 1 = length 
    print
```
One function. The loops exist once. Inside, mode picks the comparison.
*/

/*
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
*/




















// Structure 3 — one sort, comparison function (Option B)

/*
Option B — a separate function `int compare(char *a, char *b, int mode)` 
that the sort calls, so the sort body reads `if (compare(words[j], words[smallest], mode) < 0)`.
```c
void sort(char *v[], int n, int mode);
int  compare(char *a, char *b, int mode);
void swap(char *v[], int i, int j);
```
Same as 2, but the comparison moves into its own function. 
The sort stops knowing anything about strings.
*/
/*
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
*/