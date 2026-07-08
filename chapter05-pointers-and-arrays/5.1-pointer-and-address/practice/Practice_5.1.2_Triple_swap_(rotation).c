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
/*
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

/*
Key insight: & and * are opposites of each other:

&x — "give me the address of this value"
*p — "give me the value at this address"
*/

#include <stdio.h>

// Write your swapTriple function here
void swapTriple (int *a, int *b, int*c){  // //Arguments (or parameters) are inputs to a function — values or addresses you give the function so it can work with them.
    // *a mean pointer point at a , so function will go to a's address and do something there, either print it or change it value.
    int temp = 0;
    // 1. Save a's value (why? so you don't lose it)
    temp = *a;
    // 2. Put b into a
    *a = *b;
    // 3. Put c into b
    *b = *c;
    // 4. Put saved a into c , so only need 1 temp to store a.
    *c = temp;
}

int main() {
    int a, b, c;
    
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    printf("Before: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Call swapTriple here
    swapTriple (&a, &b, &c);

    printf("After:  a = %d, b = %d, c = %d\n", a, b, c);
    
    return 0;
}