/*
Practice: Basic Arrays 1 - Linear Search

Problem:
Write a function that searches for a target value in an array
and returns its index (the position where it's found).
If the value is not found, return -1.

This practices:
- Looping through an array
- Using pointers as function arguments
- Conditional logic (finding a match)

Example:
- Array: [10, 20, 30, 40, 50]
- Search for 30 -> returns 2
- Search for 99 -> returns -1
*/

#include <stdio.h>

// Write your linearSearch function here
// It should take:
//   - A pointer to an integer array
//   - The size of the array
//   - The target value to search for
// It should return the index where target is found, or -1 if not found

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    int target;
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Test 1: Search for a value that exists
    target = 30;
    printf("Searching for %d: ", target);
    // Call linearSearch here
    
    printf("\n");
    
    // Test 2: Search for another value that exists
    target = 50;
    printf("Searching for %d: ", target);
    // Call linearSearch here
    
    printf("\n");
    
    // Test 3: Search for a value that doesn't exist
    target = 99;
    printf("Searching for %d: ", target);
    // Call linearSearch here
    
    printf("\n");
    
    return 0;
}
