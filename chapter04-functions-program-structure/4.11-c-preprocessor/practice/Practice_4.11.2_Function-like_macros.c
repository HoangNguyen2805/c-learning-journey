/*
Practice 4.11.2 - Function-like Macros

Problem:
Define function-like macros and test them:

1. #define square(x) ((x) * (x))       - returns x squared
2. #define max(a, b) ((a) > (b) ? (a) : (b))  - returns larger of two
3. #define abs(x) ((x) < 0 ? -(x) : (x))      - returns absolute value

In main():
- Test each macro with simple values
- Test with expressions like square(2 + 3) to verify parentheses work
- Print the results

Example output:
square(5) = 25
square(2 + 3) = 25
max(4, 7) = 7
abs(-10) = 10
*/
/*
#include <stdio.h>

// Define your macros here

int main() {
    // Test square macro
    printf("square(5) = %d\n", square(5));
    printf("square(2 + 3) = %d\n", square(2 + 3));
    
    // Test max macro
    printf("max(4, 7) = %d\n", max(4, 7));
    
    // Test abs macro
    printf("abs(-10) = %d\n", abs(-10));
    
    return 0;
}
*/
#include <stdio.h>

// Define your macros here
#define square(x) ((x) * (x))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) < 0 ? -(x) : (x))

int main() {
    // Test square macro
    printf("square(5) = %d\n", square(5));
    printf("square(2 + 3) = %d\n", square(2 + 3));
    
    // Test max macro
    printf("max(4, 7) = %d\n", max(4, 7));
    
    // Test abs macro
    printf("abs(-10) = %d\n", abs(-10));
    
    return 0;
}