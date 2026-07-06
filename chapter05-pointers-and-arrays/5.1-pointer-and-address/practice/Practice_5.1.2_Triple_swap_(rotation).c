/*
Practice 5.1.2 - Triple Swap (Rotation) with Pointers

Problem:
Write a void swapTriple(int *a, int *b, int *c) function that rotates three values:
- a gets b's value
- b gets c's value
- c gets a's value

In main():
- Read three integers from the user
- Print them before swapTriple
- Call swapTriple to rotate them
- Print them after swapTriple
- Verify the rotation happened

Example output:
Before: a = 1, b = 2, c = 3
After:  a = 2, b = 3, c = 1
*/

#include <stdio.h>

// Write your swapTriple function here

int main() {
    int a, b, c;
    
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    printf("Before: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Call swapTriple here
    
    printf("After:  a = %d, b = %d, c = %d\n", a, b, c);
    
    return 0;
}