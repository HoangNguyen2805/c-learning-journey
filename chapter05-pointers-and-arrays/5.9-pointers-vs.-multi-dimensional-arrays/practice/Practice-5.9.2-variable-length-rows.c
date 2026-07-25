/*
Practice 5.9.2 — Variable-Length Rows
Create a data structure where each row can have different length.
This is impossible with true 2D arrays, but easy with pointer arrays.

Build:
  int *data[4];  /* 4 pointers */
  
  data[0] -> 2 ints
  data[1] -> 5 ints
  data[2] -> 3 ints
  data[3] -> 4 ints

Manually allocate and initialize each row:
  int row0[2] = {10, 20};
  int row1[5] = {1, 2, 3, 4, 5};
  etc.

Point the array to each row:
  data[0] = row0;
  data[1] = row1;
  etc.

Print all data showing row lengths.

Why this matters: Some real-world data isn't rectangular.
Example: student grades (different students take different classes).

DSA: Pointer arrays for jagged structures.
Complexity: O(total elements) to traverse.
*/

#include <stdio.h>

int main()
{
    /* Student builds jagged pointer array here */

    return 0;
}
