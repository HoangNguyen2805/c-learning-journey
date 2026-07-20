#include <stdio.h>

void printArray(int *arr, int size);

int main() {
    printf("=== Chapter 5.3: Pointers and Arrays ===\n\n");

    // Example 1: Array name is a pointer to first element
    printf("Example 1: Array decay to pointer\n");
    int arr[5] = {10, 20, 30, 40, 50};
    printf("arr = %p (address of arr[0])\n", (void *)arr);
    printf("&arr[0] = %p (should be same)\n", (void *)&arr[0]);
    printf("\n");

    // Example 2: Pointer arithmetic
    printf("Example 2: Pointer arithmetic\n");
    int *p = arr;
    printf("p points to arr[0]: %d\n", *p);
    printf("p+1 points to arr[1]: %d\n", *(p + 1));
    printf("p+2 points to arr[2]: %d\n", *(p + 2));
    printf("p+4 points to arr[4]: %d\n", *(p + 4));
    printf("\n");

    // Example 3: Equivalence of arr[i] and *(arr+i)
    printf("Example 3: arr[i] vs *(arr+i)\n");
    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr+2) = %d (same thing)\n", *(arr + 2));
    printf("\n");

    // Example 4: Iterating with pointer arithmetic
    printf("Example 4: Loop with pointer arithmetic\n");
    printf("Using arr[i]: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Using *(arr+i): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n\n");

    // Example 5: Pointers to arbitrary array elements
    printf("Example 5: Pointer to middle element\n");
    int *mid = &arr[2];  // point to arr[2] (30)
    printf("mid points to arr[2]: %d\n", *mid);
    printf("*(mid + 1) = arr[3]: %d\n", *(mid + 1));
    printf("*(mid - 1) = arr[1]: %d\n", *(mid - 1));
    printf("\n");

    // Example 6: Character arrays and pointer arithmetic
    printf("Example 6: String (char array)\n");
    char str[6] = "hello";  // 5 chars + null terminator
    char *cp = str;
    printf("String: %s\n", str);
    printf("First char (*cp): %c\n", *cp);
    printf("Third char (*(cp+2)): %c\n", *(cp + 2));
    printf("Length (by hand): ");
    int len = 0;
    while (*(cp + len) != '\0') {
        len++;
    }
    printf("%d\n", len);
    printf("\n");

    // Example 7: Char pointer arithmetic (1 byte per step)
    printf("Example 7: Pointer arithmetic with char*\n");
    printf("cp = %p\n", (void *)cp);
    printf("cp+1 = %p (1 byte forward)\n", (void *)(cp + 1));
    printf("cp+2 = %p (2 bytes forward)\n", (void *)(cp + 2));
    printf("\n");

    // Example 8: Pointer arithmetic with int* (4 bytes per step)
    printf("Example 8: Pointer arithmetic with int*\n");
    int *ip = arr;
    printf("ip = %p\n", (void *)ip);
    printf("ip+1 = %p (4 bytes forward on most systems)\n", (void *)(ip + 1));
    printf("ip+2 = %p (8 bytes forward)\n", (void *)(ip + 2));
    printf("\n");

    // Example 9: Passing array to function
    printf("Example 9: Function receives pointer\n");
    printf("Array passed to function: ");
    printArray(arr, 5);
    printf("\n\n");

    // Example 10: 2D arrays and pointers
    printf("Example 10: 2D array as pointer\n");
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("matrix[0][0] = %d\n", matrix[0][0]);
    printf("matrix[1][2] = %d\n", matrix[1][2]);
    // Cast to int* to treat as 1D
    int *mp = (int *)matrix;
    printf("As 1D array: *(mp+5) = %d (which is matrix[1][2])\n", *(mp + 5));
    printf("\n");

    return 0;
}

// Function that receives array (which is a pointer)
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}