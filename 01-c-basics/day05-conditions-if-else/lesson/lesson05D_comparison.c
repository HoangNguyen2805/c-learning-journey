#include <stdio.h>

int main() {

    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("\n--- Comparison Results ---\n");

    if (a == b) {
        printf("a is equal to b.\n");
    }

    if (a != b) {
        printf("a is not equal to b.\n");
    }

    if (a > b) {
        printf("a is greater than b.\n");
    }

    if (a < b) {
        printf("a is less than b.\n");
    }

    if (a >= b) {
        printf("a is greater than or equal to b.\n");
    }

    if (a <= b) {
        printf("a is less than or equal to b.\n");
    }

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 05D - Comparison Operators

Comparison operators compare two values.

They return true or false.

== means equal to
!= means not equal to
> means greater than
< means less than
>= means greater than or equal to
<= means less than or equal to

Example:

a = 10
b = 5

a != b is true
a > b is true
a >= b is true

Example:

a = 5
b = 5

a == b is true
a >= b is true
a <= b is true

Important:

= means assign value.
== means compare equality.

*/