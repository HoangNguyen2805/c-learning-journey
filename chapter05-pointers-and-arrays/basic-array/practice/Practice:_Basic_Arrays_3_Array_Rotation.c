/*
Practice: Basic Arrays 3 - Array Rotation

Problem:
Write a function that rotates an array LEFT by n positions.
Rotating left means: elements shift left, and elements that "fall off" 
the left end wrap around to the right end.

This practices:
- Using pointers to modify arrays
- Algorithm thinking (how to rotate without extra space)
- Testing different rotation amounts

Example:
- Array: [1, 2, 3, 4, 5]
- Rotate left by 1: [2, 3, 4, 5, 1]
- Rotate left by 2: [3, 4, 5, 1, 2]
- Rotate left by 3: [4, 5, 1, 2, 3]

Hint: You can use a helper approach:
1. Save the first n elements temporarily
2. Shift remaining elements to the left
3. Place saved elements at the end

Or find a more elegant solution!
*/

#include <stdio.h>

// Write your rotateArray function here
// It should take:
//   - A pointer to an integer array
//   - The size of the array
//   - The number of positions to rotate (n)
// It should modify the array in-place (no return needed)

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    
    printf("Original array: ");
    printArray(arr, size);
    printf("\n");
    
    // Test 1: Rotate left by 1
    printf("After rotating left by 1: ");
    // Call rotateArray here with n=1
    printArray(arr, size);
    
    // Reset array
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;
    
    printf("\n");
    
    // Test 2: Rotate left by 2
    printf("After rotating left by 2: ");
    // Call rotateArray here with n=2
    printArray(arr, size);
    
    // Reset array
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;
    
    printf("\n");
    
    // Test 3: Rotate left by 3
    printf("After rotating left by 3: ");
    // Call rotateArray here with n=3
    printArray(arr, size);
    
    return 0;
}
