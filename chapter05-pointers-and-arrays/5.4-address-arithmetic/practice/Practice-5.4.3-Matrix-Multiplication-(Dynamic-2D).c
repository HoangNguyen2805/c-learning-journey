/*
Practice 5.4.3 — Matrix Multiplication (Dynamic 2D)
Dynamically allocate two 2D matrices, multiply them, store result in third matrix, print result, free all three.
*/
/*
MATRIX MULTIPLICATION EXPLANATION:

What is Matrix Multiplication?
- Two matrices are multiplied to produce a third matrix
- If Matrix A is (m × n) and Matrix B is (n × p)
  then Result C is (m × p)

The Formula:
C[i][j] = sum of (A[i][k] * B[k][j]) for k = 0 to n-1

In plain English:
- To find C[row][col], take the ROW from matrix A
- Multiply each element by the corresponding element in COL from matrix B
- Add all the products together

Example:
A (2×3):          B (3×2):          Result C (2×2):
[1  2  3]         [7  8]            [58  64]
[4  5  6]         [9  10]           [139 154]
                  [11 12]

Calculate C[0][0]:
(1×7) + (2×9) + (3×11) = 7 + 18 + 33 = 58 ✓

Calculate C[0][1]:
(1×8) + (2×10) + (3×12) = 8 + 20 + 36 = 64 ✓

KEY POINT:
The Rule:
Matrix A (m × n) can multiply Matrix B (p × q) ONLY IF:
n == p
Number of COLUMNS in A must equal Number of ROWS in B
Otherwise multiplication is impossible!
*/
/*
COMPLEXITY
Aspect	  Value	               Why
Time	  O(m × n × p)	       Three nested loops: m rows, p cols, n multiplications
Space	  O(m×n + n×p + m×p)   Three matrices allocated
Example	  3×3 × 3×3: 27 ops	   3 × 3 × 3 = 27 multiplications
*/
/*
PSEUDOCODE
MAIN:
  1. Ask user for dimensions of Matrix A (rows_a, cols_a)
  2. Ask user for dimensions of Matrix B (rows_b, cols_b)
  
  3. Check: cols_a == rows_b? (If not, multiplication impossible, print error)
  
  4. Allocate Matrix A (rows_a × cols_a)
  5. Allocate Matrix B (rows_b × cols_b)
  6. Allocate Result Matrix C (rows_a × cols_b)
  
  7. Read values into Matrix A (nested loops)
  8. Read values into Matrix B (nested loops)
  
  9. Call multiplyMatrices(A, B, C, rows_a, cols_a, cols_b)
  
  10. Print Result Matrix C (nested loops)
  
  11. Free A, B, C
  12. Return 0

multiplyMatrices(int **A, int **B, int **C, int rows, int cols_a, int cols_b):
  FOR each row (i) from 0 to rows-1:
    FOR each column (j) from 0 to cols_b-1:
      SET C[i][j] = 0  (initialize to 0)
      
      FOR each k from 0 to cols_a-1:
        ADD to C[i][j]: (A[i][k] * B[k][j])
*/
/*
FLOWCHART
main()
  |
  +-- Get dimensions (rows_a, cols_a, rows_b, cols_b)
  |
  +-- Check: cols_a == rows_b?
  |       |
  |       NO → Print error, exit
  |
  +-- Allocate A, B, C on heap
  |
  +-- Read values into A (nested loops)
  |
  +-- Read values into B (nested loops)
  |
  +-- Call multiplyMatrices(A, B, C, ...)
  |       |
  |       +-- FOR i=0 to rows-1:
  |       |     FOR j=0 to cols_b-1:
  |       |       FOR k=0 to cols_a-1:
  |       |         C[i][j] += A[i][k] * B[k][j]
  |       |
  |       +-- Return
  |
  +-- Print Matrix C (nested loops)
  |
  +-- Free A, B, C
  |
  +-- Done!
*/
#include <stdio.h>

int main(){

  /* 
  Step 1: Collect user input to generate matrix size, 
  collect element in the matrix,
  also double check the rule n == p in oder to eligible to do matrix multiplication.
  */
  printf("Welcome to Matrix Multiplication.\n");
  printf("Note: In order for Matrix A (m * n) to be able to multiply to Matrix B (p * q), it require n = p");
  int rows_m, cols_n, rows_p, cols_q;

  printf("PLease Enter a ");

  return 0;
}

