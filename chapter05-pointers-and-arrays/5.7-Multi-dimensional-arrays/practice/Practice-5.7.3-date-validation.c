/*
Practice 5.7.3 — Add Error Checking to Date Functions
[FROM K&R Exercise 5-8]

K&R's day_of_year() and month_day() have no error checking.

Add validation:
- day_of_year(year, month, day) — validate month (1-12) and day (1-31)
- month_day(year, yearday, *pmonth, *pday) — validate yearday (1-365/366)

Return -1 if validation fails, otherwise return 0 (success).

Leap year logic:
  leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)

Test with:
  - Valid dates (e.g., March 1, 2024)
  - Invalid dates (e.g., month 13, day 32)
  - Edge cases (Feb 29 in leap vs non-leap years)

Print success/failure for each test.

Key: Use the daytab[2][13] for days per month (define it).
DSA: Data validation, conditional logic on 2D arrays.
Complexity: O(1) time per validation.
*/

#include <stdio.h>

int main()
{
    /* Test cases: (year, month, day) */
    struct {
        int year, month, day;
    } tests[] = {
        {2024, 3, 1},      /* valid: March 1, 2024 (leap) */
        {2024, 2, 29},     /* valid: Feb 29 in leap year */
        {2023, 2, 29},     /* invalid: Feb 29 in non-leap year */
        {2024, 13, 1},     /* invalid: month 13 */
        {2024, 1, 32},     /* invalid: day 32 in January */
        {2024, 4, 31}      /* invalid: day 31 in April */
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    /* Student writes validation functions and test code here */

    return 0;
}
