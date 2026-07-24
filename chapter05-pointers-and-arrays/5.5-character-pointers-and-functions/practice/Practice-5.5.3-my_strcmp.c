/*
Practice 5.5.3 — my_strcmp (Pointer Comparison)

PROBLEM:
Implement your own version of strcmp() using pointer arithmetic.
Compare two strings character by character.

RETURN VALUES:
  - Return 0 if strings are identical
  - Return negative if first string is lexicographically smaller
  - Return positive if first string is lexicographically larger

INPUT/OUTPUT EXAMPLE:
  my_strcmp("apple", "apple")   → 0
  my_strcmp("apple", "banana")  → negative (because 'a' < 'b')
  my_strcmp("zebra", "apple")   → positive (because 'z' > 'a')
  my_strcmp("apple", "app")     → positive (because "apple" is longer)

CONSTRAINTS:
- Use pointer arithmetic (p++, *p, etc.) — do NOT use array indexing [i]
- Do NOT call strcmp() or any string library functions
- Both strings are null-terminated

HINTS:
- Create two pointers: one for each string
- Compare characters at both pointers
- If they differ, return the difference: (*s1 - *s2)
- If both hit null terminator, return 0
- Advance both pointers together

DSA CONCEPT:
  Pointer traversal, lexicographic comparison
  
TIME COMPLEXITY: O(n) where n = length of shorter string
SPACE COMPLEXITY: O(1)
*/
/*
#include <stdio.h>

// Function signature — implement this
int my_strcmp(char *s1, char *s2);

int main() {
    // Test your my_strcmp function here
    // Test: identical strings, different strings, different lengths
    // Print the return values to verify
    
    return 0;
}

// Implement my_strcmp below
int my_strcmp(char *s1, char *s2) {
    // Your code here
}
*/
/*
pseudocode for my_strcmp:
FUNCTION my_strcmp(s1 pointer, s2 pointer):
    
    WHILE (both s1 and s2 are not at null terminator):
        IF character at s1 is different from character at s2:
            RETURN the difference: (*s1 - *s2)
        
        Move s1 pointer forward
        Move s2 pointer forward
    
    IF both reached null terminator at same time:
        RETURN 0 (strings are identical)
*/
#include <stdio.h>

// Function signature — implement this
int my_strcmp(char *s1, char *s2);

int main() {

    printf("Comparing word under lexicographically unit measurement.\n");
    char s1[100];
    char s2[100];

    printf("Enter first word: ");
    scanf(" %[^\n]", s1);

    printf("Enter second word: ");
    scanf(" %[^\n]", s2);

    // Test your my_strcmp function here
    // Test: identical strings, different strings, different lengths
    // Print the return values to verify
    int result = my_strcmp(s1, s2);

    if (result == 0) {
        printf("Strings are equal\n");
    } else if (result < 0) {
        printf("First is smaller\n");
    } else {
        printf("Second is larger\n");
    }
    
    return 0;
}

// Implement my_strcmp below
int my_strcmp(char *s1, char *s2) {
    // Your code here
    // Case 1
    while(*s1 != '\0' && *s2 != '\0'){ 
      //Case 2 and 3
      if(*s1 != *s2){                    // If different
          return (*s1 - *s2);            // Return difference immediately
      } // Case 2 and 3
    s1++;                                // If same, just increment
    s2++;                                // and continue
}
// return (*s1 - *s2) = '\0' - '\0' = 0 ✅ Case 1
return (*s1 - *s2);// -> result = 0      // After loop: handle remaining chars
}
/*
Why does the final return (*s1 - *s2) work?

Case 1: Both strings end at same time ("apple" vs "apple")

*s1 = '\0', *s2 = '\0'
'\0' - '\0' = 0 ✅

Case 2: s1 is longer ("apple" vs "app")

*s1 = 'l', *s2 = '\0'
'l' - '\0' = positive ✅

Case 3: s2 is longer ("app" vs "apple")

*s1 = '\0', *s2 = 'l'
'\0' - 'l' = negative ✅
*/