/*
Practice: Basic Arrays 2 - Find Duplicates

Problem:
Write a function that finds all duplicate values in an array
and counts how many times each duplicate appears.

This practices:
- Nested loops (comparing elements)
- Using pointers as function arguments
- Tracking which elements you've already counted
- Printing results in a useful format

Example:
- Array: [1, 2, 2, 3, 2, 4, 4, 5]
- Duplicates:
  - 2 appears 3 times
  - 4 appears 2 times

Hint: You need to avoid counting the same duplicate multiple times.
One approach: when you find a duplicate, mark it somehow or track it.
*/

#include <stdio.h>

// Write your findDuplicates function here
// It should take:
//   - A pointer to an integer array
//   - The size of the array
// It should print each duplicate value and its count

int main() {
    int arr[] = {1, 2, 2, 3, 2, 4, 4, 5, 3, 3};
    int size = 10;
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    printf("Duplicates found:\n");
    // Call findDuplicates here
    
    return 0;
}
