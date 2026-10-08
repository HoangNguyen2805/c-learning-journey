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
/*
#include <stdio.h>

int main()
{
    int src[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int dst[4][3];

    // Student writes code here 

    return 0;
}
*/

/*
Transpose: rows become columns, columns become rows

src[3][4] (3 rows, 4 columns):
    1  2  3  4
    5  6  7  8
    9  10 11 12

dst[4][3] (4 rows, 3 columns):
    1  5  9
    2  6  10
    3  7  11
    4  8  12

Formula: dst[j][i] = src[i][j]

When i=0, j=0: src[0][0]=1 → dst[0][0]=1
When i=0, j=1: src[0][1]=2 → dst[1][0]=2
When i=0, j=2: src[0][2]=3 → dst[2][0]=3
When i=0, j=3: src[0][3]=4 → dst[3][0]=4

First row of src becomes first column of dst.
*/

#include <stdio.h>

void transpose(int src[3][4] , int dst[4][3]);

int main()
{
    int src[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int dst[4][3];

    // Student writes code here 
    transpose(src, dst);
   
    printf("Transposed matrix:\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", dst[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void transpose(int src[3][4] , int dst[4][3]){
    // for every row of src qill = to every collums of dst
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            dst[j][i] = src[i][j];
        }
    }
}