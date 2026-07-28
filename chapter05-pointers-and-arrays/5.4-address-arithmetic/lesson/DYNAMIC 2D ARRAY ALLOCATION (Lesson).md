/*
WHY DYNAMIC 2D ALLOCATION?

Fixed 2D array (what you know):
  int matrix[3][4];  // Size hardcoded, known at compile time

Dynamic 2D array (what we need):
  User enters: rows = 5, cols = 7 (at RUNTIME)
  We need to allocate 5×7 matrix

HOW IT WORKS:

A 2D array is an ARRAY OF ARRAYS

Visual:
  int **matrix means:
    - First * = pointer to rows (array of pointers)
    - Second * = each row is pointer to integers
    
  matrix[0] → pointer to Row 0 integers
  matrix[1] → pointer to Row 1 integers
  matrix[2] → pointer to Row 2 integers

ALLOCATION STEPS:

Step 1: Create the row pointers
  int **matrix = malloc(rows * sizeof(int *));
  
  This allocates space for 'rows' pointers
  
  Example with rows=3:
  matrix[0] ─→ (empty, not allocated yet)
  matrix[1] ─→ (empty, not allocated yet)
  matrix[2] ─→ (empty, not allocated yet)

Step 2: Create each row
  for(int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
  }
  
  This allocates space for 'cols' integers in EACH row
  
  Example with rows=3, cols=4:
  matrix[0] ─→ [0] [0] [0] [0]
  matrix[1] ─→ [0] [0] [0] [0]
  matrix[2] ─→ [0] [0] [0] [0]

NOW YOU CAN USE IT:
  matrix[0][0] = 5;
  matrix[1][2] = 10;
  matrix[2][3] = 15;

FREEING IS REVERSE:

Step 1: Free each row
  for(int i = 0; i < rows; i++) {
    free(matrix[i]);
  }

Step 2: Free the row pointers
  free(matrix);
  matrix = NULL;
*/