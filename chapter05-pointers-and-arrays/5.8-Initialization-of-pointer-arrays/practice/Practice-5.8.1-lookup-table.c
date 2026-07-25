/*
Practice 5.8.1 — Build a Lookup Table
Create a function that maps state abbreviations to full names.

state_name(char *abbr) — return full state name for 2-letter abbreviation

Use a static array of pointers initialized with state data.

Example:
  state_name("CA") -> "California"
  state_name("TX") -> "Texas"
  state_name("ZZ") -> "Unknown state"

Store pairs: abbreviation string and full name string.
One approach: two parallel static arrays.
Another approach: struct array (but not required for this exercise).

Test with 5-10 states and some invalid abbreviations.

Print results in a table.

Key: Learn how static initialization patterns work for lookup tables.
DSA: Linear search on string data, parallel arrays.
Complexity: O(n) per lookup (n = number of states).
*/

#include <stdio.h>
#include <string.h>

int main()
{
    /* Test lookups */
    char *test_abbrs[] = {"CA", "TX", "NY", "FL", "ZZ", "XX"};
    int num_tests = sizeof(test_abbrs) / sizeof(test_abbrs[0]);

    printf("State Lookup Table\n");
    printf("==================\n");

    /* Student writes lookup function and test loop here */

    return 0;
}
