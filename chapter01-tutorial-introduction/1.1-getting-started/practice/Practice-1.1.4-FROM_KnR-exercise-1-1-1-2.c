/*
[FROM K&R] Exercise 1-1 and 1-2 — Experiment with printf

Exercise 1-1: Run the "hello, world" program on your system

Exercise 1-2: Experiment with the printf() function. In particular:
  - What happens if the argument string to printf does not end with \n?
  - What if you remove the \n from the middle of the string?
  - What if you use multiple \n in a row?

Problem:
Write and test a program that demonstrates these printf behaviors.

Your task:
1. Write a main program that uses printf in different ways
2. Test what happens WITHOUT \n at the end
3. Test what happens WITH multiple \n characters
4. Observe and document the output behavior

Example code to test:
  printf("Hello, World!");    // No newline
  printf("Line1\n");
  printf("\n\nDouble newline"); // Multiple newlines
*/

#include <stdio.h>

int main()
{
    /* Test 1: printf WITHOUT newline at the end */
    printf("This line has no newline");
    printf("This continues on same line\n");
    
    /* Test 2: printf WITH newline at the end */
    printf("This line has a newline\n");
    printf("This starts on a new line\n");
    
    /* Test 3: Multiple newlines in a row */
    printf("One line\n");
    printf("\n");  /* Empty line */
    printf("Two lines after blank\n");
    
    /* Test 4: Newline in the middle */
    printf("First part\nSecond part\n");
    
    /* Test 5: Multiple newlines together */
    printf("Top\n\n\nBottom (3 newlines above)\n");

    return 0;
}

/*
OBSERVATIONS:
- When printf() doesn't end with \n, the next printf() output appears on the same line
- Multiple \n characters create blank lines
- \n always forces output to the next line
- The program doesn't automatically add a newline at the end
*/
