/*
Practice 1.1.2 — Fix Errors

Problem:
The following code has syntax errors. Your job is to:
1. Identify each error
2. Fix it
3. Make the program compile and run successfully

Broken Code:
    #include <stdio.h>

    int main() {
        printf("Learning to code\n")
        printf("Errors help me learn\n");
        printf("C requires attention to detail\n")
        return 0;
    }

Expected Output (after fixing):
    Learning to code
    Errors help me learn
    C requires attention to detail

Constraints:
- Fix the syntax errors without changing the logic
- Make sure the program compiles with gcc
- Make sure the output matches exactly

Complexity: O(1) — just printing

Key Concept:
- Semicolons are required at the end of statements
- The compiler catches syntax errors and helps you fix them
- Pay attention to error messages from gcc
*/

#include <stdio.h>

int main() {
    printf("Learning to code\n");
    printf("Errors help me learn\n");
    printf("C requires attention to detail\n");
    
    return 0;
}

/*
ERRORS FOUND:
1. Line 1: Missing semicolon after first printf
   - printf("Learning to code\n")  <- Missing ;
   - Should be: printf("Learning to code\n");

2. Line 3: Missing semicolon after third printf
   - printf("C requires attention to detail\n")  <- Missing ;
   - Should be: printf("C requires attention to detail\n");

LESSON:
Every statement in C ends with a semicolon.
When gcc says "error: expected ';'", look for a missing semicolon on the previous line.
*/
