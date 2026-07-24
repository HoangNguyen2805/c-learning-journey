/*
[FROM K&R] Exercise 1-3 (adapted) — Explore Escape Sequences

Problem:
Experiment with different escape sequences in C.
The main escape sequences you should know:
  \n = newline
  \t = tab
  \\ = backslash
  \" = double quote
  \' = single quote

Your task:
Write a program that demonstrates at least 5 different escape sequences.

Example:
  - Use \n to create multiple lines
  - Use \t to indent text
  - Use \\ to print a backslash
  - Use \" to print a quote inside a string
  - Combine them

Key Point from K&R:
Understanding escape sequences is essential for formatting output correctly.
*/

#include <stdio.h>

int main()
{
    printf("Testing Escape Sequences\n");
    printf("========================\n\n");
    
    /* Demonstrate \n (newline) */
    printf("Line 1\n");
    printf("Line 2\n");
    printf("Line 3\n\n");
    
    /* Demonstrate \t (tab) */
    printf("No tab\n");
    printf("\tWith one tab\n");
    printf("\t\tWith two tabs\n\n");
    
    /* Demonstrate \\ (backslash) */
    printf("This is a backslash: \\\n");
    printf("Path example: C:\\Users\\name\n\n");
    
    /* Demonstrate \" (double quote) */
    printf("He said \"Hello, World!\"\n");
    printf("Quote in middle: \"escape sequences\"\n\n");
    
    /* Demonstrate combinations */
    printf("Formatted line:\n");
    printf("\t\"Name:\"\tHoang\n");
    printf("\t\"Goal:\"\tMaster C\n");
    
    return 0;
}

/*
WHAT TO OBSERVE:
- \n moves to the next line
- \t indents by approximately 4-8 spaces
- \\ prints a single backslash
- \" lets you print quotes inside strings
- You can combine multiple escape sequences
- Some escape sequences overlap in function (e.g., \n creates spacing)
*/
