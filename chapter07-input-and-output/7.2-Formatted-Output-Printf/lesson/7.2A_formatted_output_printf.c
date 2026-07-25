/*
7.2A - Formatted Output printf: worked examples
Compile: gcc -Wall -Wextra -o 7.2A 7.2A_formatted_output_printf.c
*/
#include <stdio.h>

int main(void)
{
    /* 1: the conversion zoo */
    printf("=== Example 1: conversions ===\n");
    printf("d=%d o=%o x=%x X=%X u=%u c=%c s=%s %%=literal\n",
           255, 255, 255, 255, 255u, 'A', "hi");

    /* 2: width - minimum columns */
    printf("\n=== Example 2: width ===\n");
    printf("[%d]\n[%6d]\n[%-6d]<-left\n", 42, 42, 42);

    /* 3: zero padding */
    printf("\n=== Example 3: zero pad ===\n");
    printf("id=%05d  price=%08.2f\n", 42, 3.14159);

    /* 4: precision on floats */
    printf("\n=== Example 4: float precision ===\n");
    double pi = 3.14159265358979;
    printf("%%f=%f  %%.2f=%.2f  %%.9f=%.9f\n", pi, pi, pi);
    printf("%%e=%e  %%g=%g\n", pi * 1e6, pi * 1e6);

    /* 5: precision on strings - the K&R table */
    printf("\n=== Example 5: the hello world table ===\n");
    const char *s = "hello, world";
    printf(":%s:\n", s);
    printf(":%10s:\n", s);
    printf(":%.10s:\n", s);
    printf(":%-10s:\n", s);
    printf(":%.15s:\n", s);
    printf(":%-15s:\n", s);
    printf(":%15.10s:\n", s);
    printf(":%-15.10s:\n", s);

    /* 6: sign and space flags */
    printf("\n=== Example 6: + and space flags ===\n");
    printf("%+d %+d\n", 42, -42);
    printf("% d % d\n", 42, -42);

    /* 7: # alternate forms */
    printf("\n=== Example 7: # flag ===\n");
    printf("%#o %#x %#X\n", 255, 255, 255);

    /* 8: runtime width/precision with * */
    printf("\n=== Example 8: star specifiers ===\n");
    int width = 12, prec = 5;
    printf("[%*d]\n", width, 42);
    printf("[%.*s]\n", prec, "truncate me");

    /* 9: table building - align a mini report */
    printf("\n=== Example 9: aligned table ===\n");
    printf("%-10s %8s %6s\n", "item", "price", "qty");
    printf("%-10s %8.2f %6d\n", "pencil", 0.5, 100);
    printf("%-10s %8.2f %6d\n", "notebook", 3.25, 40);
    printf("%-10s %8.2f %6d\n", "backpack", 29.99, 3);

    /* 10: sprintf + the %s safety rule */
    printf("\n=== Example 10: sprintf and safety ===\n");
    char buf[64];
    int n = sprintf(buf, "(%d,%d)", 3, 4);
    printf("sprintf built \"%s\" (%d chars)\n", buf, n);
    const char *tricky = "gotcha %d %s";
    printf("%s\n", tricky);    /* SAFE: never printf(tricky) directly */
    printf("printf returns chars written: last full line was %d? no - see code\n", n);

    return 0;
}
