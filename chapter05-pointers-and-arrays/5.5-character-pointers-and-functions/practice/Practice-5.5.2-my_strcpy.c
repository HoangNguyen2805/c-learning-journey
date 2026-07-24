/*
Practice 5.5.2 — my_strcpy (Pointer Copy)

PROBLEM:
Implement your own version of strcpy() using pointer arithmetic.
Copy characters from source string to destination string, including the null terminator.

INPUT/OUTPUT EXAMPLE:
  Source: "Hello"
  Destination before: "     " (uninitialized)
  Destination after: "Hello"

CONSTRAINTS:
- Use pointer arithmetic (p++, *p, etc.) — do NOT use array indexing [i]
- Do NOT call strcpy() or any string library functions
- Copy the null terminator as well
- Assume destination has enough space (we won't test buffer overflow)

HINTS:
- Create two pointers: one for source, one for destination
- Dereference source, assign to destination
- Advance both pointers
- Stop when you copy the null terminator

DSA CONCEPT:
  Pointer traversal, data copying
  
TIME COMPLEXITY: O(n) where n = length of source string
SPACE COMPLEXITY: O(1)
*/
/*
#include <stdio.h>

// Function signature — implement this
char *my_strcpy(char *dest, char *src);

int main() {
    // Test your my_strcpy function here
    // Try with different strings
    // Print destination to verify the copy worked
    
    return 0;
}

// Implement my_strcpy below
char *my_strcpy(char *dest, char *src) {
    // Your code here
    // Should return dest (pointer to the copied string)
}
*/
/*
FUNCTION my_strcpy(dest pointer, src pointer):
    
    WHILE (current character in src is not null terminator):
        Copy character from src to dest
        Move src pointer forward
        Move dest pointer forward
    
    Copy the null terminator to dest
    Move dest pointer forward
    
    RETURN dest
*/
#include <stdio.h>

char *my_strcpy(char *source, char *dest);

int main (){

  char source[100];
  char dest[100];

  printf("Enter your message: ");
  scanf("%[^\n]", source);

  my_strcpy(source, dest);

  printf("Displace message: %s\n", dest);

  return 0;
}

char *my_strcpy(char *source, char *dest){ // // ← Add * before my_strcpy ,The * means "pointer to char", not just "char".
  while(*source != '\0'){
    *dest = *source;  // Copy character from src to dest
    source++;         // Move src pointer forward
    dest++;           // Move dest pointer forward
  } // at this point dest is missing '\n' so we have to copy it before we return it.
  *dest = *source;    // Copy the null terminator
  return dest;        // Move dest pointer forward
}