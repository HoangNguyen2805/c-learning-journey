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
/*
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
*/
// a = the gate (the address)
// *a = what's inside the gate (the value at that address)
// *a = *b; means "put what's at b's address into a's address"
// temp = *a; means "look inside the address a points to and grab the value"
#include <stdio.h>

// Write your swap function here

void swap(int *a, int *b){
    int temp = 0;
    temp = *a; // Line 1: You saved a's value in temp
    *a = *b; // Line 2: You need to put b's value into a's address (overwrite what's at a's address)
    *b = temp; // Line 3: Then put temp (the original a value) into b's address
    
}

int main() {
    int a, b;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    // Call swap here
    swap(&a, &b); // passes the addresses to the function, but it doesn't print anything.
    printf("After swap: a = %d, b = %d\n", a, b);
    
    return 0;
}
