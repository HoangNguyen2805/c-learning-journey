/*
Section 1.1 — Getting Started
Example Programs Demonstrating Basic Concepts

Each example demonstrates ONE concept.
Compile and run each one to see the output.
*/

#include <stdio.h>

/* Example 1: Simplest program — prints one line */
void example1_hello_world()
{
    printf("=== Example 1: Hello World ===\n");
    printf("Hello, World!\n");
    printf("\n");
}

/* Example 2: Multiple printf statements */
void example2_multiple_lines()
{
    printf("=== Example 2: Multiple Lines ===\n");
    printf("Line 1\n");
    printf("Line 2\n");
    printf("Line 3\n");
    printf("\n");
}

/* Example 3: Newline behavior — with and without \n */
void example3_newline_behavior()
{
    printf("=== Example 3: Newline Behavior ===\n");
    printf("Without newline");
    printf(" still on same line\n");
    printf("With newline\n");
    printf("Next line\n");
    printf("\n");
}

/* Example 4: Escape sequences — \t (tab) and \n (newline) */
void example4_escape_sequences()
{
    printf("=== Example 4: Escape Sequences ===\n");
    printf("No tab\n");
    printf("\tWith tab\n");
    printf("\t\tDouble tab\n");
    printf("Column1\tColumn2\tColumn3\n");
    printf("\n");
}

/* Example 5: Printing numbers as strings */
void example5_numbers_as_text()
{
    printf("=== Example 5: Numbers as Text ===\n");
    printf("The number 123 in text\n");
    printf("Phone: 555-1234\n");
    printf("Year: 2024\n");
    printf("\n");
}

/* Example 6: Special characters in strings */
void example6_special_characters()
{
    printf("=== Example 6: Special Characters ===\n");
    printf("Quotes: \"Hello\"\n");
    printf("Apostrophe: It's C\n");
    printf("Exclamation: Wow!\n");
    printf("Question: What's this?\n");
    printf("\n");
}

/* Example 7: Combining strings with printf */
void example7_string_concatenation()
{
    printf("=== Example 7: String Concatenation ===\n");
    printf("My ");
    printf("name ");
    printf("is ");
    printf("Hoang\n");
    printf("This is four separate printf calls on one line!\n");
    printf("\n");
}

/* Example 8: Creating formatted output */
void example8_formatted_output()
{
    printf("=== Example 8: Formatted Output ===\n");
    printf("Name:\tAlice\n");
    printf("Age:\t25\n");
    printf("City:\tBoston\n");
    printf("\n");
}

/* Example 9: Empty lines and spacing */
void example9_spacing()
{
    printf("=== Example 9: Spacing ===\n");
    printf("Line 1\n");
    printf("\n");  /* Empty line */
    printf("Line 3 (with blank line between)\n");
    printf("\n");  /* Empty line */
    printf("Line 5\n");
    printf("\n");
}

/* Example 10: Combining text and escape sequences */
void example10_mixed_output()
{
    printf("=== Example 10: Mixed Output ===\n");
    printf("Start\n");
    printf("\tIndented\n");
    printf("\t\tMore indented\n");
    printf("Back to normal\n");
    printf("\n");
}

/* Main function that runs all examples */
int main()
{
    printf("Section 1.1 — Getting Started Examples\n");
    printf("======================================\n\n");

    example1_hello_world();
    example2_multiple_lines();
    example3_newline_behavior();
    example4_escape_sequences();
    example5_numbers_as_text();
    example6_special_characters();
    example7_string_concatenation();
    example8_formatted_output();
    example9_spacing();
    example10_mixed_output();

    printf("======================================\n");
    printf("All examples completed!\n");

    return 0;
}
