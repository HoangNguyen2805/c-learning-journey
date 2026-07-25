/*
5.10A - Command-line Arguments: worked examples
Compile: gcc -Wall -Wextra -o 5.10A 5.10A_command_line_arguments.c
Run with arguments, e.g.: ./5.10A hello world 42
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ex1_show_argc(int argc);
void ex2_show_argv(int argc, char *argv[]);
void ex3_echo_subscript(int argc, char *argv[]);
void ex4_echo_pointer(int argc, char *argv[]);
void ex5_argv0_name(char *argv[]);
void ex6_numeric_args(int argc, char *argv[]);
void ex7_null_sentinel(char *argv[]);
void ex8_find_flag(int argc, char *argv[]);
void ex9_longest_arg(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf("=== Example 1: argc ===\n");
    ex1_show_argc(argc);

    printf("\n=== Example 2: argv contents ===\n");
    ex2_show_argv(argc, argv);

    printf("\n=== Example 3: echo (subscript style) ===\n");
    ex3_echo_subscript(argc, argv);

    printf("\n=== Example 4: echo (pointer style) ===\n");
    ex4_echo_pointer(argc, argv);

    printf("\n=== Example 5: program name ===\n");
    ex5_argv0_name(argv);

    printf("\n=== Example 6: numeric conversion with atoi ===\n");
    ex6_numeric_args(argc, argv);

    printf("\n=== Example 7: NULL sentinel walk ===\n");
    ex7_null_sentinel(argv);

    printf("\n=== Example 8: detect a -v flag ===\n");
    ex8_find_flag(argc, argv);

    printf("\n=== Example 9: longest argument ===\n");
    ex9_longest_arg(argc, argv);

    return 0;
}

/* 1: argc counts every word, including the program name */
void ex1_show_argc(int argc)
{
    printf("argc = %d (program name + %d argument(s))\n", argc, argc - 1);
}

/* 2: each argv[i] is a string */
void ex2_show_argv(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
}

/* 3: K&R echo, array subscript version */
void ex3_echo_subscript(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    printf("\n");
}

/* 4: K&R echo, pointer version (works on local copies) */
void ex4_echo_pointer(int argc, char *argv[])
{
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
}

/* 5: argv[0] is the program name as invoked */
void ex5_argv0_name(char *argv[])
{
    printf("This program was started as: %s\n", argv[0]);
}

/* 6: arguments are strings; atoi converts numeric ones */
void ex6_numeric_args(int argc, char *argv[])
{
    int i, sum = 0, count = 0;
    for (i = 1; i < argc; i++) {
        int v = atoi(argv[i]);
        if (v != 0 || argv[i][0] == '0') {   /* crude "is numeric" check */
            sum += v;
            count++;
        }
    }
    printf("numeric-looking args: %d, their sum: %d\n", count, sum);
}

/* 7: argv[argc] is guaranteed NULL - loop without argc */
void ex7_null_sentinel(char *argv[])
{
    char **p;
    for (p = argv; *p != NULL; p++)
        printf("[%s] ", *p);
    printf("\n(stopped at NULL sentinel)\n");
}

/* 8: scan for a "-v" option flag anywhere in the arguments */
void ex8_find_flag(int argc, char *argv[])
{
    int i, verbose = 0;
    for (i = 1; i < argc; i++)
        if (strcmp(argv[i], "-v") == 0)
            verbose = 1;
    printf("verbose flag present: %s\n", verbose ? "yes" : "no");
}

/* 9: cumulative review - strlen over the pointer array */
void ex9_longest_arg(int argc, char *argv[])
{
    int i;
    char *longest = NULL;
    size_t maxlen = 0;
    for (i = 1; i < argc; i++)
        if (strlen(argv[i]) > maxlen) {
            maxlen = strlen(argv[i]);
            longest = argv[i];
        }
    if (longest)
        printf("longest argument: \"%s\" (%zu chars)\n", longest, maxlen);
    else
        printf("no arguments given\n");
}
