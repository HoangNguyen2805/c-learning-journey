/*
7.1A - Standard Input and Output: worked examples
Compile: gcc -Wall -Wextra -o 7.1A 7.1A_standard_input_and_output.c
Run:     echo "Hello World 123" | ./7.1A
         ./7.1A < somefile.txt
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;
    long chars = 0, letters = 0, digits = 0, spaces = 0, lines = 0;
    int last = EOF;

    printf("=== One pass over stdin, many demos at once ===\n");
    printf("(pipe or redirect input into this program)\n\n");

    /* THE filter loop: examples 1-8 all live inside it */
    while ((c = getchar()) != EOF) {

        /* 1: count raw characters */
        chars++;

        /* 2: classify with <ctype.h> */
        if (isalpha(c)) letters++;
        else if (isdigit(c)) digits++;
        else if (isspace(c)) spaces++;

        /* 3: count lines by '\n' */
        if (c == '\n')
            lines++;

        /* 4: echo transformed - swap case as we go */
        if (isupper(c))
            putchar(tolower(c));
        else if (islower(c))
            putchar(toupper(c));
        else
            putchar(c);

        last = c;
    }

    /* 5: EOF ended the loop - c is int so EOF was representable */
    printf("\n--- stream ended (getchar returned EOF) ---\n");

    /* 6: the tallies */
    printf("chars=%ld letters=%ld digits=%ld spaces=%ld lines=%ld\n",
           chars, letters, digits, spaces, lines);

    /* 7: detect missing final newline (classic text-tool concern) */
    if (chars > 0 && last != '\n')
        printf("note: input did not end with a newline\n");

    /* 8: printf and putchar share stdout, strictly in order */
    putchar('[');
    printf("mixed putchar+printf output works");
    putchar(']');
    putchar('\n');

    /* 9: remind how redirection changes NOTHING in this code */
    printf("try: ./7.1A < 7.1A_standard_input_and_output.c | tail -5\n");

    return 0;
}
