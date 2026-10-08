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
/*
#include <stdio.h>

int main()
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Student writes code here 

    return 0;
}
*/
#include <stdio.h>

int matrix_sum(int v[][4], int rows);
double matrix_average(int v[][4], int rows);

int main()
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Student writes code here 
    printf("The sum of the matrix[3][4] is = %d\n", matrix_sum(matrix, 3));
    printf("The average of the matrix[3][4] is = %.2f\n", matrix_average(matrix, 3));
    

    return 0;
}

int matrix_sum(int v[][4], int rows){
    /*
    arr [ ] [ ] is already a pointer all we need is a nested for loop to change number of 
    these two [ ] [ ] to collect value of each elemet of this 2D to add up.
    */
   // for(int i = 0; i < arr [i] []; i++){ -> you cant code like this because this is a limitation of C
   // you have to manually full in the row size and collum size of the array as parameter
   // Ex: int matrix_sum(int v[][4], int rows)
   // so we can you that manual rows as a condition to stop for loop.
   int sum = 0;
   for(int i = 0; i < rows; i++){
    for(int j = 0; j < 4; j++){
        sum = sum + v[i][j];
    }
   }
   /* The signature rule say 2D array arr[][#], in the first [] is allow to be empty but the second [] need to have some value (can NOT be empty).
   So if there is situaltion where seccond [] is arbitrary column counts
   If the user inputs their own column count, you have three options:

    Use a 1D array — flatten it yourself:
    c
        int arr[rows * cols];  // user inputs rows and cols
        arr[i * cols + j]  // access element at row i, col j
        Use dynamic allocation (what you learned in 5.6 with malloc):
    c
        int **arr = malloc(rows * sizeof(int*));
        for(int i = 0; i < rows; i++)
            arr[i] = malloc(cols * sizeof(int));
        Use an array of pointers:
    c
        int *arr[rows];  // each row is a separate malloc'd array
   */
  return sum;
}


double matrix_average(int v[][4], int rows){
    /*
    First - need the sum of matrix so I need to call the function mint matrix_sum
    Second - need to calculate how many element was in 2D array
    Third sum / # of element = average
     So return average;
    */
    
    double average = ( (double)matrix_sum(v, rows) / (rows * 4));
    // average will be return decimal number because of division so we'll cast the function matrix_sum as (double temporally)
    return average;
}