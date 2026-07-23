/*
Practice 5.5.1 — my_strlen (Pointer Arithmetic)

PROBLEM:
Implement your own version of strlen() using pointer arithmetic.
Count the number of characters in a string (excluding the null terminator).

INPUT/OUTPUT EXAMPLE:
  Input string: "Hello"
  Output: 5
  
  Input string: ""
  Output: 0

CONSTRAINTS:
- Use pointer arithmetic (p++, *p, etc.) — do NOT use array indexing [i]
- Do NOT call strlen() or any string library functions
- Handle empty strings correctly
- The string is null-terminated ('\0')

HINTS:
- Start with a pointer pointing to the first character
- Advance the pointer until you hit the null terminator
- Count how many times you advanced

DSA CONCEPT:
  Pointer traversal, linear search
  
TIME COMPLEXITY: O(n) where n = length of string
SPACE COMPLEXITY: O(1)
*/
/*
#include <stdio.h>

// Function signature — implement this
int my_strlen(char *s);

int main() {
    // Test your my_strlen function here
    // Try with different strings including empty string
    
    return 0;
}

// Implement my_strlen below
int my_strlen(char *s) {
    // Your code here
}
*/
/*pseudocode
int main() {
    // Step 1: Declare char array
    // Step 2: Ask user for input
    // Step 3: Read input
    // Step 4: Call my_strlen()
    // Step 5: Print result
    
    return 0;
}
*/
#include <stdio.h>

// Function signature — implement this
int my_strlen(char *s);

int main() {
    
    char s[100];
    printf("User input without white space (\"hello\"): ");
    scanf(" %s", s);
    // Test your my_strlen function here
    printf("The length = %d\n", my_strlen(s));

    // Try with different strings including empty string
    printf("User input with white space (\"hello, how are you?\"): ");
    scanf(" %[^\n]", s);
    // Test your my_strlen function here
    printf("The length = %d\n", my_strlen(s));
    
    return 0;
}

// Implement my_strlen below
int my_strlen(char *s) {
    // Your code here
    int len = 0; // set count unit = 0
    while (*s != '\0'){ // while pointer point at value, and the value is not reach NULL terminal.
        len++; // each while loop add 1 to count while going through char *s one by one
        s++; // while each loop move one element to the RIGHT by one using pointer arithmetic
    } // end loop when while reach NULL terminal
    return len; // return value of len when while loop reach NULL terminal.
}