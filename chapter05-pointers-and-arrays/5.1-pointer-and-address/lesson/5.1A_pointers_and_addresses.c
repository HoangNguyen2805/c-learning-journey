/*
5.1A - Pointers and Addresses (example code)

Demonstrates:
- Declaring a pointer
- Using & (address-of)
- Using * (dereference)
- How changing *p changes the original variable
- The connection to scanf's use of &
*/

#include <stdio.h>

int main() {
    int x = 5;
    int *p;      // declare p as a pointer to an int

    p = &x;      // p now holds the address of x

    printf("--- Before dereferencing ---\n");
    printf("x = %d\n", x);
    printf("&x = %p\n", (void *)&x);
    printf("p  = %p\n", (void *)p);
    printf("*p = %d\n", *p);

    printf("\n--- Changing x through *p ---\n");
    *p = 100;    // changes the value AT the address p points to

    printf("x = %d\n", x);   // 100! Changing *p changed x itself
    printf("*p = %d\n", *p); // 100

    printf("\n--- Changing x directly also shows through *p ---\n");
    x = 250;
    printf("x  = %d\n", x);
    printf("*p = %d\n", *p); // 250, since *p always reflects x's current value

    printf("\n--- The scanf connection ---\n");
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);   // &n gives scanf the ADDRESS of n so it can write into it directly
    printf("You entered: %d\n", n);

    return 0;
}
