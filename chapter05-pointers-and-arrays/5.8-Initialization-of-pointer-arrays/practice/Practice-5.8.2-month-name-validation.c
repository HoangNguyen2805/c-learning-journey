/*
Practice 5.8.2 — Enhance Month Name with Validation
Improve the month_name function from the lesson.

month_name_validated(int n, int *valid) — return month name and set valid flag

If n is 1-12, return the month name and set *valid = 1.
If n is invalid, return "Unknown" and set *valid = 0.

Alternative: return NULL for invalid months.

Test:
  - Valid months (1-12)
  - Invalid months (0, 13, -1, 100)
  - Boundary cases (1, 12)

Print a table of results with validation status.

Key: Practice using pointer parameters to return status.
Learn when static arrays save space vs when they waste it.
DSA: Error handling with out parameters.
Complexity: O(1) per lookup.
*/

#include <stdio.h>

int main()
{
    int tests[] = {0, 1, 6, 12, 13, -1, 100};
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("Month Name Lookup (with validation)\n");
    printf("===================================\n");
    printf("N    Valid   Name\n");
    printf("---  -----   ----\n");

    /* Student writes validation function and test loop here */

    return 0;
}
