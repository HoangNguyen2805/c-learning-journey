#include <stdio.h>
#include <string.h>

/* Helper functions for date conversion */
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    printf("=== Chapter 5.7: Multi-dimensional Arrays ===\n\n");

    /* Example 1: Basic 2D array declaration and initialization */
    printf("Example 1: Basic 2D array\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("matrix[0][0] = %d\n", matrix[0][0]);
    printf("matrix[1][2] = %d\n", matrix[1][2]);
    printf("matrix[2][3] = %d\n", matrix[2][3]);
    printf("\n");

    /* Example 2: Looping over a 2D array */
    printf("Example 2: Print entire 2D array\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /* Example 3: Pointer arithmetic with rows */
    printf("Example 3: Row as pointer\n");
    int *row = matrix[1];  /* row points to start of row 1 */
    printf("Row 1: %d %d %d %d\n", row[0], row[1], row[2], row[3]);
    printf("\n");

    /* Example 4: Sum of all elements */
    printf("Example 4: Sum of all elements\n");
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Sum: %d\n", sum);
    printf("\n");

    /* Example 5: Column sum */
    printf("Example 5: Sum each column\n");
    for (int j = 0; j < 4; j++) {
        int col_sum = 0;
        for (int i = 0; i < 3; i++) {
            col_sum += matrix[i][j];
        }
        printf("Column %d sum: %d\n", j, col_sum);
    }
    printf("\n");

    /* Example 6: Character 2D array (strings as rows) */
    printf("Example 6: 2D char array (fixed-width strings)\n");
    char names[4][10] = {
        "Alice",
        "Bob",
        "Charlie",
        "Diana"
    };
    for (int i = 0; i < 4; i++) {
        printf("names[%d]: %s\n", i, names[i]);
    }
    printf("\n");

    /* Example 7: Days per month (K&R style) */
    printf("Example 7: Days per month (leap year table)\n");
    static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    printf("Days in February (non-leap): %d\n", daytab[0][2]);
    printf("Days in February (leap): %d\n", daytab[1][2]);
    printf("Days in December (any year): %d\n", daytab[0][12]);
    printf("\n");

    /* Example 8: Using day_of_year function */
    printf("Example 8: Convert month/day to day-of-year\n");
    int doy = day_of_year(2024, 3, 1);  /* March 1, 2024 (leap year) */
    printf("March 1, 2024 is day %d of the year\n", doy);
    doy = day_of_year(2023, 3, 1);      /* March 1, 2023 (non-leap) */
    printf("March 1, 2023 is day %d of the year\n", doy);
    printf("\n");

    /* Example 9: Using month_day function */
    printf("Example 9: Convert day-of-year to month/day\n");
    int month, day;
    month_day(2024, 60, &month, &day);  /* day 60 of leap year */
    printf("Day 60 of 2024 (leap): month %d, day %d\n", month, day);
    month_day(2023, 60, &month, &day);  /* day 60 of non-leap year */
    printf("Day 60 of 2023 (non-leap): month %d, day %d\n", month, day);
    printf("\n");

    /* Example 10: Memory layout demonstration */
    printf("Example 10: Memory addresses show row-major order\n");
    int small[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("small[0][0] at %p\n", (void *)&small[0][0]);
    printf("small[0][1] at %p (offset +%ld bytes)\n", 
           (void *)&small[0][1], 
           (long)(&small[0][1] - &small[0][0]) * sizeof(int));
    printf("small[1][0] at %p (offset +%ld bytes)\n", 
           (void *)&small[1][0], 
           (long)(&small[1][0] - &small[0][0]) * sizeof(int));
    printf("(Elements stored contiguously in memory, row by row)\n");
    printf("\n");

    return 0;
}

/* day_of_year: convert month and day to day of year */
int day_of_year(int year, int month, int day)
{
    static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: convert day of year to month and day */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
