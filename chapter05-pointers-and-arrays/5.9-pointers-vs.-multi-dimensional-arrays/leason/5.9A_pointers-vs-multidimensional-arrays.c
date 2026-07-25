#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("=== Chapter 5.9: Pointers vs. Multi-dimensional Arrays ===\n\n");

    /* Example 1: True 2D array - memory layout */
    printf("Example 1: True 2D array (contiguous)\n");
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("Array a[2][3]:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("a[%d][%d] at %p = %d\n", i, j, (void *)&a[i][j], a[i][j]);
        }
    }
    printf("\n");

    /* Example 2: Pointer array - separate storage */
    printf("Example 2: Pointer array (fragmented)\n");
    int row0[3] = {1, 2, 3};
    int row1[3] = {4, 5, 6};
    int *b[2] = {row0, row1};
    printf("Array b[2] (pointers):\n");
    for (int i = 0; i < 2; i++) {
        printf("b[%d] points to %p\n", i, (void *)b[i]);
    }
    printf("Data accessed through pointers:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("b[%d][%d] at %p = %d\n", i, j, (void *)&b[i][j], b[i][j]);
        }
    }
    printf("\n");

    /* Example 3: Size difference */
    printf("Example 3: Memory allocation difference\n");
    printf("True 2D array a[2][3]: %lu bytes total\n", 
           sizeof(a));
    printf("Pointer array b[2]: %lu bytes for pointers\n", 
           sizeof(b));
    printf("(Plus %lu bytes for row0, %lu for row1)\n",
           sizeof(row0), sizeof(row1));
    printf("\n");

    /* Example 4: Variable-length rows (strings) */
    printf("Example 4: Variable-length string storage\n");
    char *months[] = {
        "January",    /* 8 bytes */
        "Feb",        /* 4 bytes */
        "March",      /* 6 bytes */
        "April",      /* 6 bytes */
        "May"         /* 4 bytes */
    };
    printf("String lengths using pointer array:\n");
    for (int i = 0; i < 5; i++) {
        printf("months[%d] = \"%s\" (%lu bytes)\n", 
               i, months[i], strlen(months[i]) + 1);
    }
    printf("\n");

    /* Example 5: Fixed-width array wastes space */
    printf("Example 5: Fixed-width 2D array (wasteful)\n");
    char fixed_months[5][10] = {
        "January",
        "Feb",
        "March",
        "April",
        "May"
    };
    printf("Each row allocated 10 bytes:\n");
    for (int i = 0; i < 5; i++) {
        printf("fixed_months[%d] = \"%s\" (allocated 10, used %lu)\n",
               i, fixed_months[i], strlen(fixed_months[i]) + 1);
    }
    printf("Total: 50 bytes allocated\n");
    printf("With pointer array: ~32 bytes for pointers + ~28 bytes for strings = ~60 bytes\n");
    printf("(Pointer array slightly larger but more flexible)\n");
    printf("\n");

    /* Example 6: Accessing elements works the same syntax-wise */
    printf("Example 6: Both use [i][j] syntax\n");
    printf("2D array:     a[1][2] = %d\n", a[1][2]);
    printf("Pointer array: b[1][2] = %d\n", b[1][2]);
    printf("(Syntax identical, but different mechanisms underneath)\n");
    printf("\n");

    /* Example 7: Manually allocated pointer array */
    printf("Example 7: Dynamically allocated pointer array\n");
    int *matrix[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = (int *)malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = i * 4 + j + 1;
        }
    }
    printf("Dynamically allocated 3x4 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        free(matrix[i]);
    }
    printf("\n");

    /* Example 8: Variable-length rows in pointer array */
    printf("Example 8: Pointer array with variable row lengths\n");
    int row_a[2] = {10, 20};
    int row_b[4] = {30, 40, 50, 60};
    int row_c[3] = {70, 80, 90};
    int *variable[3] = {row_a, row_b, row_c};
    
    printf("Row 0: ");
    for (int j = 0; j < 2; j++) printf("%d ", variable[0][j]);
    printf("\n");
    
    printf("Row 1: ");
    for (int j = 0; j < 4; j++) printf("%d ", variable[1][j]);
    printf("\n");
    
    printf("Row 2: ");
    for (int j = 0; j < 3; j++) printf("%d ", variable[2][j]);
    printf("\n");
    printf("(Different row lengths possible with pointer array)\n");
    printf("\n");

    /* Example 9: Pointer arithmetic is different */
    printf("Example 9: Pointer arithmetic differences\n");
    printf("2D array a[1][1] address: %p\n", (void *)&a[1][1]);
    printf("  = base + (1 * 3 + 1) * sizeof(int)\n");
    
    printf("Pointer array b[1][1] address: %p\n", (void *)&b[1][1]);
    printf("  = *(b[1] + 1)\n");
    printf("\n");

    /* Example 10: Comparison in code */
    printf("Example 10: Choosing the right data structure\n");
    printf("If all rows same length, use 2D array: int a[m][n]\n");
    printf("If rows vary in length, use pointer array: int *p[m]\n");
    printf("For strings, pointer array almost always best.\n");
    printf("\n");

    return 0;
}
