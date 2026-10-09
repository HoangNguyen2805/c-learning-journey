/*
Practice 5.8.2 — Binary Search on a Sorted Static Keyword Table

Make a static, alphabetically SORTED pointer array of C keywords:

    static char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", ...
    };

(Use at least 15 real C keywords. Order matters — double-check it.)

Write:
  int my_strcmp(char *s, char *t);
  int is_sorted(char *tab[], int n);
        returns 1 if every tab[i] <= tab[i+1], else 0
  int binsearch_word(char *word, char *tab[], int n);
        returns the index of word in tab, or -1 if not found

Rules:
  - Get n in main with sizeof(keywords) / sizeof(keywords[0]).
    (Then explain in a comment why you can't do that inside
    binsearch_word.)
  - Call is_sorted first; if the table isn't sorted, print a warning
    and stop — binary search gives wrong answers on unsorted data.
  - binsearch_word uses low / high / mid, comparing with my_strcmp.
  - Also count and print how many comparisons each search took.

Test with: "int", "while", "auto", "volatile", "banana", "a", "zzz"
Output style:     int       -> found at <index>   (<k> comparisons)
                  banana    -> not found          (<k> comparisons)
(The numbers depend on your table — check one by hand.)

Questions to answer before coding (write them as comments):
  1. my_strcmp returns <0, 0, or >0. Which way does each move low/high?
  2. Your loop condition: low < high or low <= high? Walk through a
     1-element table to decide.
  3. For n = 32, what's the maximum number of comparisons? Why?

DSA:        Binary search (on strings), sortedness check
Best way:   Iterative binary search — halve the range each step
Complexity: binsearch O(log n) comparisons; is_sorted O(n);
            each string comparison costs O(L) for word length L;
            O(1) extra space
*/

#include <stdio.h>

int my_strcmp(char *s, char *t);
int is_sorted(char *tab[], int n);
int binsearch_word(char *word, char *tab[], int n);

int main()
{
    // Student writes code here
    return 0;
}
