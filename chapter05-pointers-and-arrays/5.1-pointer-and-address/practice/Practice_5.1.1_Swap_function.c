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

/*
Key insight: & and * are opposites of each other:

&x — "give me the address of this value"
*p — "give me the value at this address"
*/
#include <stdio.h>

// Write your swap function here
void swap (int *a, int *b) { //Arguments (or parameters) are inputs to a function — values or addresses you give the function so it can work with them.
    // *a mean pointer point at a , so function will go to a's address and do something there, either print it or change it value.
    int temp = 0;
    // 1. temp = *a — save a's value (the location still exists)
    temp = *a;
    // 2. *a = *b — overwrite a's location with b's value
    *a = *b;
    // 3. *b = temp — put the saved value into b's location
    *b = temp;
}

int main() {
    int a, b;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    // Call swap here
    swap(&a, &b);  // passes the addresses (where the variables live), not the value

    printf("After swap: a = %d, b = %d\n", a, b);
    
    return 0;
} 