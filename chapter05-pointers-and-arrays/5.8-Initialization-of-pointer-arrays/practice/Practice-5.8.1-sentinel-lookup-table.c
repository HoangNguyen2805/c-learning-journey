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
/*
#include <stdio.h>

int   my_strcmp(char *s, char *t);
int   table_len(char **tab);
char *state_name(char *code);

int main()
{
    // Student writes code here
    return 0;
}
*/
//

/*
=== PSEUDOCODE: Practice 5.8.1 ===

SECTION 1 — DATA (outside all functions, static)
    abbr = array of char*: 8 state codes ... NULL
    full = array of char*: 8 full names  ... NULL
    rule: abbr[i] and full[i] = same state (same order!)
    NULL = end of table, tells loops when to stop

SECTION 2 — my_strcmp(s, t)
    loop while letter at s == letter at t:
        if letter at s is '\0' → return 0     (same string)
        move s and t to next letter
    return (letter at s) - (letter at t)      (different)

SECTION 3 — table_len(tab)
    tab = whatever table the caller passes in
    p starts at tab (slot 0)
    count starts at 0
    while slot p points at is not NULL:
        count + 1
        p moves to next slot
    return count

SECTION 4 — state_name(code)
    code = one test string passed in by main
    i starts at 0
    loop while abbr[i] is not NULL:
        if my_strcmp(code, abbr[i]) is 0 → return full[i]
        i + 1
    return "Unknown state"          (searched all, no match)

SECTION 5 — main
    tests = "CA","TX","NY","FL","ZZ","","ca", NULL
    n = table_len(tests)            → 7
    loop i from 0 to n-1:
        name = state_name(tests[i])
        print tests[i] -> name
    print "Table length:" table_len(abbr)    → 8
    return 0

CALL FLOW:
    main ──> state_name ──> my_strcmp
      └────> table_len
*/

#include <stdio.h>

/* state-abbreviation mean:
TX - abbreviation
Texas - state
*/
// SECTION 1 — DATA
static char *abbr[] = { "CA" , "TX" , "NY" , "FL" , "IL" , "WA" , "OH" , "GA" , NULL};
static char *full[] = { "California" , "Texas" , "New York" , "Florida" , "Illinois" , "Washington" , "Ohio" , "Georgia" , NULL};

int   my_strcmp(char *s, char *t);
int   table_len(char **tab);
char *state_name(char *code);

int main()
{
    // Student writes code here
    return 0;
}

// SECTION 2 — my_strcmp(s, t)