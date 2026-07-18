/* Increment via Pointer
Practice 5.2.1: Write a function that increments a value via pointer.
Write a function that takes a pointer to an integer and increments the value at that address by 1. Test it with different values.
*/
// do a before and after solution of the user input
#include <stdio.h>

void upOne(int *a);

int main(){

    int a;
    printf("Before and After increments the value at the adress by 1 using function.\n"
           "Enter your value: ");
    scanf("%d", &a);

    printf("Before, a is %d\n", a);

    upOne(&a); // when you call the function you need & because you need to reach a new address

    printf("After, a is %d\n", a); // 

    return 0;
}

void upOne(int *a){
    (*a)++;
}