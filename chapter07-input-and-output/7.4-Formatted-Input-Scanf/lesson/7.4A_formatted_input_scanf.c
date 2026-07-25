/*
7.4A - Formatted Input scanf: worked examples
Compile: gcc -Wall -Wextra -o 7.4A 7.4A_formatted_input_scanf.c
NOTE: this example uses sscanf on canned strings so it runs without typing.
      Everything shown applies to scanf on live stdin identically.
*/
#include <stdio.h>

int main(void)
{
    /* 1: basic conversions + the & rule (sscanf: string stands for stdin) */
    printf("=== Example 1: ints and doubles ===\n");
    int n;
    double x;
    int got = sscanf("42 3.75", "%d %lf", &n, &x);
    printf("converted=%d  n=%d  x=%.2f\n", got, n, x);

    /* 2: return value = success count */
    printf("\n=== Example 2: return value ===\n");
    int n2;
    got = sscanf("99 banana", "%d %d", &n, &n2);
    printf("\"99 banana\" vs \"%%d %%d\" -> %d conversion(s)\n", got);

    /* 3: %s reads ONE word and null-terminates */
    printf("\n=== Example 3: %%s = one word ===\n");
    char word[32];
    sscanf("hello world", "%s", word);       /* array: no & needed */
    printf("read word: \"%s\" (stopped at the space)\n", word);

    /* 4: %c does NOT skip whitespace */
    printf("\n=== Example 4: %%c vs \" %%c\" ===\n");
    char c1, c2;
    sscanf("  A", "%c", &c1);                /* grabs a space!      */
    sscanf("  A", " %c", &c2);               /* leading blank in fmt skips */
    printf("%%c got '%c' (0x%02x); \" %%c\" got '%c'\n", c1, c1, c2);

    /* 5: literal characters must match - date parsing */
    printf("\n=== Example 5: literal matching ===\n");
    int d, m, y;
    got = sscanf("25/12/2025", "%d/%d/%d", &d, &m, &y);
    printf("date: day=%d month=%d year=%d (matched %d)\n", d, m, y, got);
    got = sscanf("25-12-2025", "%d/%d/%d", &d, &m, &y);
    printf("wrong separator: only %d converted\n", got);

    /* 6: assignment suppression with * */
    printf("\n=== Example 6: %%*s skips a field ===\n");
    int score;
    sscanf("player1 8500", "%*s %d", &score);
    printf("skipped the name, score=%d\n", score);

    /* 7: width limits - protect your buffers */
    printf("\n=== Example 7: %%31s width cap ===\n");
    char safe[8];
    sscanf("supercalifragilistic", "%7s", safe);   /* 7 chars + '\0' */
    printf("buffer[8] safely holds: \"%s\"\n", safe);

    /* 8: %d vs %i */
    printf("\n=== Example 8: %%i understands 0x and 0 prefixes ===\n");
    int a, b;
    sscanf("0x1f", "%i", &a);
    sscanf("017", "%i", &b);
    printf("%%i: 0x1f -> %d, 017 -> %d (hex+octal recognized)\n", a, b);

    /* 9: the robust line+sscanf pattern */
    printf("\n=== Example 9: line-then-sscanf ===\n");
    const char *lines[] = { "10 alpha", "junk!!", "30 gamma" };
    for (int i = 0; i < 3; i++) {
        int id;
        char name[16];
        if (sscanf(lines[i], "%d %15s", &id, name) == 2)
            printf("line %d parsed: id=%d name=%s\n", i, id, name);
        else
            printf("line %d rejected: \"%s\"\n", i, lines[i]);
    }

    /* 10: the calculator loop shape (shown, not run) */
    printf("\n=== Example 10: K&R rudimentary calculator shape ===\n");
    printf("while (scanf(\"%%lf\", &v) == 1) sum += v;\n");
    printf("try it live: echo \"1 2.5 4\" | (your build with real scanf)\n");

    return 0;
}
