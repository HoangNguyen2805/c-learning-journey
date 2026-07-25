/*
Practice 5.10.3 - Argument Sorter

Problem:
Print the command-line arguments (excluding argv[0]) in sorted order:

    ./argsort banana apple cherry
    apple
    banana
    cherry

Numeric mode with -n: compare as numbers, not text:

    ./argsort -n 100 25 3
    3
    25
    100

Requirements:
- Sort the argv pointers themselves (swap char* values) - do NOT copy strings.
- Implement insertion sort over argv[1..argc-1].
- Write your own mystrcmp(char *s, char *t) using pointer style (*s, *t, s++, t++).
- With -n, compare atoi(a) vs atoi(b) instead of mystrcmp.

DSA/Algorithm Focus: insertion sort on an array of pointers (this is exactly
how K&R sorts lines in 5.6 - argv IS a pointer array).
Best approach: insertion sort - simple, in-place, stable.
Complexity: O(k^2) comparisons for k args, O(1) extra space.
Constraints: no qsort, no strcmp from <string.h>.

Hints (Socratic):
- When you "swap two strings" here, what actually gets swapped - characters or addresses?
- Why is swapping pointers O(1) while swapping the strings themselves would be O(m)?
- How can one comparison function pointer... wait - that's 5.11. For now: how would
  an if/else on the -n flag select which comparison to run inside the sort loop?
*/

#include <stdio.h>
#include <stdlib.h>

int mystrcmp(char *s, char *t);

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

int mystrcmp(char *s, char *t){
    // Student writes code here
    return 0;
}
