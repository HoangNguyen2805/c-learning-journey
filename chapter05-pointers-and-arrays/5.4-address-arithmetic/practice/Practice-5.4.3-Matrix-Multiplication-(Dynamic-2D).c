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

void multiplyMatrices(int **A, int **B, int **C, int rows_m, int rows_p, int cols_n, int cols_q);

int main(){

  /* 
  Step 1: Collect user input to generate matrix size, 
  collect element in the matrix,
  also double check the rule n == p in oder to eligible to do matrix multiplication.
  */
  printf("Welcome to Matrix Multiplication.\n");
  printf("Note: In order for Matrix A (m * n) to be able to multiply to Matrix B (p * q), it require n = p");
  int rows_m, cols_n, rows_p, cols_q;

  printf("PLease Enter the amount of rows (m) for Matrix A : ");
  scanf(" %d", &rows_m);
  
  
  printf("PLease Enter the amount of columns (n) for Matrix A : ");
  scanf(" %d", &cols_n);
  
  printf("PLease Enter the amount of row (p) for Matrix B : ");
  scanf(" %d", &rows_p);
  
  printf("PLease Enter the amount of columns (q) for Matrix B : ");
  scanf(" %d", &cols_q);

  if(cols_n == rows_p){
    printf("Matrix A: %d x %d\n", rows_m, cols_n);
    printf("Matrix B: %d x %d\n", rows_p, cols_q);
    printf("n = (%d) == p(%d), \n", cols_n, rows_p);
    printf("Let Input Matrix A and Matrix B.\n");
  } else {
    printf("n = (%d) NOT = p(%d), \n", cols_n, rows_p);
    printf("Unable to perform Matrix Multiplication!!!\n");
    return 1;
  }

  // Step 2: Once we know the size of each Matrix , now we can generate 3 malloc to store user in put and do calculation.
  // Use ** double ppointer for 2D array (arr[i][j])
  
  // Create space to collecting and storing Matrix A's integer element.

  // Create space memory for Matrix A's row.
  int **arrMatrixArow = malloc(rows_m * sizeof(int *));
  if(arrMatrixArow == NULL) {
    printf("Memory allocation failed for Matrix A rows\n");
    return 1;
  }
  // Then assign each Matrix A's row a # of column by using for loop to asign each elemnt of
  //     **arrMatrixArow a colum that size of cols_n * sizeof(arrMatrixArow).
  // bassicall multiply # of col to each row of matrix a using for loop.
  for(int i = 0; i < rows_m; i++){
    arrMatrixArow[i] = malloc(cols_n * sizeof(int));
    if(arrMatrixArow[i] == NULL) {
        printf("Memory allocation failed for Matrix C columns\n");
        return 1;
    }
  }
  // Matrix A is Done 

  // Same with Matrix B
  int **arrMatrixBrow = malloc(rows_p * sizeof(int *));
  if(arrMatrixBrow == NULL) {
    printf("Memory allocation failed for Matrix A rows\n");
    return 1;
  }
  // Then assign each Matrix A's row a # of column by using for loop to asign each elemnt of
  //     **arrMatrixArow a colum that size of cols_n * sizeof(arrMatrixArow).
  // bassicall multiply # of col to each row of matrix a using for loop.
  for(int i = 0; i < rows_p; i++){
    arrMatrixBrow[i] = malloc(cols_q * sizeof(int));
    if(arrMatrixBrow[i] == NULL) {
        printf("Memory allocation failed for Matrix C columns\n");
        return 1;
    }
  }
  // Matrix B is Done 

  /* Now let do some linear algebra to figure out the size of C
  Matrix C dimensions are:

  Rows of C = Rows of A
  Columns of C = Columns of B

  A is rows_m × cols_n
  B is rows_p × cols_q

  C is rows_m × cols_q
        ↑         ↑
      from A    from B
  */
 // Row C = Row A
 int **arrMatrixCrow = malloc(rows_m * sizeof(int *));
  if(arrMatrixCrow == NULL) {
    printf("Memory allocation failed for Matrix A rows\n");
    return 1;
  }
  // Now Col C = Col B
  for(int i = 0; i < rows_m; i++){
    arrMatrixCrow[i] = malloc(cols_q * sizeof(int));
    if(arrMatrixCrow[i] == NULL) {
        printf("Memory allocation failed for Matrix C columns\n");
        return 1;
    }
  }

  // Step 3: Collect Value of each element of MAtrix A and Matrix B from user input.
  // i is row, j is column , use nested for loop to assign use in put into correct location.
  /*
  Column 0  Column 1  Column 2  Column 3
              ↓         ↓         ↓         ↓
Row 0:  A[0][0]  A[0][1]  A[0][2]  A[0][3]  ←
Row 1:  A[1][0]  A[1][1]  A[1][2]  A[1][3]  ←
Row 2:  A[2][0]  A[2][1]  A[2][2]  A[2][3]  ←
  ↓

  Reading order (as if it were 1D):

1st:  A[0][0]
2nd:  A[0][1]
3rd:  A[0][2]
4th:  A[0][3]
5th:  A[1][0]  ← Start row 1
6th:  A[1][1]
7th:  A[1][2]
8th:  A[1][3]
9th:  A[2][0]  ← Start row 2
10th: A[2][1]
11th: A[2][2]
12th: A[2][3]
  */
 // the for nested for loop of A[i][j]
 /* stay at row i until colmun j is go from 0 , 1 , 2 , 3. 
 And that is how we move from left to right in row i = 0
 */
  printf("Matrix A value will be filled in order of left to right and top to bottom of A[row][Columns].\n");
  for(int i = 0; i < rows_m; i++){
    for(int j = 0; j < cols_n; j++){
    printf("Enter value for A[%d, %d]: ", i, j);
    scanf(" %d", &arrMatrixArow[i][j]);
    }
  }

  printf("Matrix B value will be filled in order of left to right and top to bottom of B[row][Columns].\n");
  for(int i = 0; i < rows_p; i++){
    for(int j = 0; j < cols_q; j++){
    printf("Enter value for B[%d, %d]: ", i, j);
    scanf(" %d", &arrMatrixBrow[i][j]);
    }
  }

  // Step 4: Calculation, We create void function to manipulate matrix A and B and call it.
  multiplyMatrices(arrMatrixArow, arrMatrixBrow, arrMatrixCrow, rows_m, rows_p, cols_n, cols_q);

  // Step 5: Displace the Matrix C result.
  printf("\n=== Result Matrix C (%d x %d) ===\n", rows_m, cols_q);
  for(int i = 0; i < rows_m; i++){
    for(int j = 0; j < cols_q; j++){
      printf(" %d, ", arrMatrixCrow[i][j]);
    }
    printf("\n");
  }

  // LAST STEP: free the memory from malloc
  // If malloc was in the loop, then we have to use same loop to free it

  // Free Matrix A
  for(int i = 0; i < rows_m; i++) {
      free(arrMatrixArow[i]);
  }
  free(arrMatrixArow);
  arrMatrixArow = NULL;

  // Free Matrix B
  for(int i = 0; i < rows_p; i++) {
      free(arrMatrixBrow[i]);
  }
  free(arrMatrixBrow);
  arrMatrixBrow = NULL;

  // Free Matrix C
  for(int i = 0; i < rows_m; i++) {
      free(arrMatrixCrow[i]);
  }
  free(arrMatrixCrow);
  arrMatrixCrow = NULL;

  return 0;
}

// Step 4:
/*
for(int i = 0; i < rows_a; i++) {           // Each row of C
    for(int j = 0; j < cols_b; j++) {       // Each column of C
        C[i][j] = 0;  // Initialize to 0
        
        for(int k = 0; k < cols_a; k++) {   // Multiply and sum
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
*/
/*HOW FORMULAR WORK 
For C[i][j]:
1. Take ROW i from Matrix A
2. Take COLUMN j from Matrix B
3. Multiply them element-by-element
4. Add all the products then asign it to C[i][j]
*/
/* EXAMPLE
C[0][1] = ?

ROW 0 from A: [1, 2, 3]
COL 1 from B: [8, 10, 12]

Multiply each pair:
(1 × 8) + (2 × 10) + (3 × 12) = 8 + 20 + 36 = 64

C[0][1] = 64
*/
/* Another perspective of FORMULA
C[i][j] = SUM of (A[i][k] * B[k][j])
           ↑              ↑       ↑
         result      row i    col j
*/
void multiplyMatrices(int **A, int **B, int **C, int rows_m, int rows_p, int cols_n, int cols_q){
  // We need 3 loop for this
  // Remember 
  //Rows of C = Rows of A
  //Columns of C = Columns of B

  // 1st Loop: for each row of C
  for(int i = 0; i < rows_m; i++){ // A[i][k] goes across each column in ROW i of A
    // 2nd Loop: for each column of C
    for(int j = 0; j < cols_q; j++){ // B[k][j] goes down each row in COLUMN j of B
      // 3rd Loop: Multiplycation of i and j
      // Remember n == p ? So k < cols_n ✅ Works OR
      //                      k < rows_p ✅ Also works (same value!)
      //             cols_n = A[i][k]
      //             rows_p = B[k][j]
      C[i][j] = 0; //Since we adding += we have to INITIALIZE to 0 first
      for(int k = 0; k < cols_n; k++) {// You multiply EVERY column in A's row with EVERY row in B's column!
        // formular C[i][j] = SUM of (A[i][k] * B[k][j])
        // y += x; mean y = y + x;
        // where y is current C 
        // and x is (A[i][j] * B[i][j])
        // so y = y + x mean stacking up the adding of (A[i][j] * B[i][j])
        C[i][j] += (A[i][k] * B[k][j]);

        // if k < rows_p , then formular change to
        //     C[i][j] += (A[k][j] * B[i][k]);
      }
    } 
  }
}