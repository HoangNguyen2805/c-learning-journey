/*
Practice 5.8.1 — Sentinel-Terminated Lookup Table (Parallel Arrays)

Build a state-abbreviation lookup using TWO static pointer arrays
that line up index-for-index:

    abbr[]  = { "CA", "TX", "NY", ... , NULL }
    full[]  = { "California", "Texas", "New York", ... , NULL }

abbr[i] and full[i] always describe the same state.
Both tables end with NULL instead of a stored count.

Write:
  int   my_strcmp(char *s, char *t);       your own version from 5.5
  int   table_len(char **tab);             count entries by walking to NULL
  char *state_name(char *code);            "CA" -> "California",
                                           unknown -> "Unknown state"

Rules:
  - Put at least 8 states in the tables.
  - table_len must walk with a char ** pointer (p++), NOT with tab[i].
  - state_name finds the INDEX in abbr[], then uses that index in full[].
  - No strcmp from <string.h>; no sizeof to find the length.

Test in main with: "CA", "TX", "NY", "FL", "ZZ", "", "ca"
Print one line per test, e.g.   CA -> California
Then print the table length.

Questions to answer before coding (write them as comments):
  1. In table_len, what is the type of *p, and what does p++ move past?
  2. Why can't you just compare code == abbr[i]?
  3. What should "ca" (lowercase) return with your my_strcmp, and why?

DSA:        Linear search over parallel arrays; sentinel-terminated arrays
Best way:   Single pass: compare each abbr[i] until match or NULL
Complexity: O(n) time per lookup (n = number of states), O(1) extra space
*/

#include <stdio.h>

int   my_strcmp(char *s, char *t);
int   table_len(char **tab);
char *state_name(char *code);

int main()
{
    // Student writes code here
    return 0;
}
