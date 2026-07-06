/*
Practice 5.1.1 - Swap Function with Pointers

Problem:
Write a void swap(int *a, int *b) function that swaps two integers.

In main():
- Read two integers from the user
- Print them before swap
- Call swap to exchange them
- Print them after swap
- Verify the swap worked

Example output:
Before swap: a = 5, b = 10
After swap: a = 10, b = 5
*/

#include <stdio.h>

// Write your swap function here

int main() {
    int a, b;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    // Call swap here
    
    printf("After swap: a = %d, b = %d\n", a, b);
    
    return 0;
}