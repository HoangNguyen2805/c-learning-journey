/*
Practice 5.7.2 — Matrix Transpose
Write a function that transposes a matrix (swap rows and columns).

transpose(int src[3][4], int dst[4][3])

A 3x4 matrix becomes 4x3 (rows become columns).

Example:
  Input (3x4):        Output (4x3):
  1  2  3  4          1  5  9
  5  6  7  8          2  6  10
  9  10 11 12         3  7  11
                      4  8  12

Print both matrices to verify.

Key: Both dimensions must be specified (src[3][4] and dst[4][3]).
DSA: 2D array manipulation, nested loops with index swapping.
Complexity: O(m * n) time, O(m * n) space (for output).
*/

#include <stdio.h>

int main()
{
    int src[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int dst[4][3];

    /* Student writes code here */

    return 0;
}
