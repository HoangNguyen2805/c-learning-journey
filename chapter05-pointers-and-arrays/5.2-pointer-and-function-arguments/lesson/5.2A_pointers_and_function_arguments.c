/*
5.2A - Pointers and Function Arguments (example code)

Demonstrates:
- Functions modifying variables through pointers
- Arrays decaying to pointers
- Pointer arithmetic
- String manipulation with pointers
- Multiple return values through pointer arguments
*/

#include <stdio.h>

// Example 1: Function modifies a single variable
void increment(int *ptr) {
    *ptr = *ptr + 1;
}

// Example 2: Function returns status, modifies through pointer
int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;  // error
    }
    *result = a / b;
    return 1;  // success
}

// Example 3: Function modifies array in-place
void doubleValues(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;
    }
}

// Example 4: String length using pointer arithmetic
int myStrlen(char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;  // move pointer to next character
    }
    return count;
}

// Example 5: Multiple return values through pointers
void getMinMax(int *arr, int size, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main() {
    printf("=== Example 1: Increment ===\n");
    int x = 5;
    printf("Before: x = %d\n", x);
    increment(&x);
    printf("After:  x = %d\n", x);

    printf("\n=== Example 2: Divide with error handling ===\n");
    int result;
    if (divide(10, 2, &result)) {
        printf("10 / 2 = %d\n", result);
    }
    if (!divide(10, 0, &result)) {
        printf("Error: division by zero\n");
    }

    printf("\n=== Example 3: Array modification ===\n");
    int numbers[] = {1, 2, 3, 4, 5};
    printf("Before: ");
    for (int i = 0; i < 5; i++) printf("%d ", numbers[i]);
    printf("\n");
    doubleValues(numbers, 5);
    printf("After:  ");
    for (int i = 0; i < 5; i++) printf("%d ", numbers[i]);
    printf("\n");

    printf("\n=== Example 4: String length with pointers ===\n");
    char name[] = "Claude";
    printf("Length of '%s': %d\n", name, myStrlen(name));

    printf("\n=== Example 5: Min and Max ===\n");
    int vals[] = {3, 7, 2, 9, 1, 5};
    int minVal, maxVal;
    getMinMax(vals, 6, &minVal, &maxVal);
    printf("Array: 3 7 2 9 1 5\n");
    printf("Min: %d, Max: %d\n", minVal, maxVal);

    printf("\n=== Array name as pointer ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;  // arr decays to pointer to first element
    printf("arr[0] = %d\n", arr[0]);
    printf("*arr = %d\n", *arr);
    printf("*p = %d\n", *p);
    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr+2) = %d\n", *(arr + 2));
    printf("*(p+2) = %d\n", *(p + 2));
    printf("p[2] = %d\n", p[2]);

    return 0;
}
