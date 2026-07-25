/*
Practice 5.7.1 — Matrix Sum
Write two functions that compute statistics on a 2D array of integers.

matrix_sum(int a[][4], int rows) — return sum of all elements
matrix_average(int a[][4], int rows) — return average of all elements

Pass a 3x4 matrix and print the sum and average.

Key: Remember the column count (4) must be in the function signature.
Without it, the compiler can't calculate row stride.

Constraint: Use nested loops, no shortcuts.
DSA: Array traversal, nested iteration.
Complexity: O(rows * 4) time, O(1) space.
*/

#include <stdio.h>

int main()
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    /* Student writes code here */

    return 0;
}
