/*
5.12A - Complicated Declarations: worked examples
Compile: gcc -Wall -Wextra -o 5.12A 5.12A_complicated_declarations.c
Each example DECLARES a gnarly type, USES it, and PRINTS its English reading.
*/
#include <stdio.h>

int getval(void);
int getval2(void);
char firstchar(void);
int addone(int x);
int timestwo(int x);

int main(void)
{
    /* 1: array of pointers vs pointer to array */
    printf("=== Example 1: int *a[3] vs int (*b)[3] ===\n");
    int x = 1, y = 2, z = 3;
    int *a[3] = { &x, &y, &z };            /* array[3] of pointer to int */
    int nums[3] = { 10, 20, 30 };
    int (*b)[3] = &nums;                    /* pointer to array[3] of int */
    printf("a: array[3] of pointer to int  -> *a[1] = %d\n", *a[1]);
    printf("b: pointer to array[3] of int  -> (*b)[1] = %d\n", (*b)[1]);

    /* 2: function returning pointer vs pointer to function */
    printf("\n=== Example 2: int *f() vs int (*pf)() ===\n");
    int *ip;
    static int stored = 99;
    ip = &stored;                           /* stand-in for f() returning int* */
    int (*pf)(void) = getval;               /* pointer to function returning int */
    printf("int *ip (via ptr)          = %d\n", *ip);
    printf("int (*pf)(void) call       = %d\n", (*pf)());

    /* 3: pointer to pointer */
    printf("\n=== Example 3: int **pp ===\n");
    int v = 42;
    int *p = &v;
    int **pp = &p;                          /* pointer to pointer to int */
    printf("v=%d  *p=%d  **pp=%d\n", v, *p, **pp);

    /* 4: array of function pointers */
    printf("\n=== Example 4: int (*tab[2])(int) ===\n");
    int (*tab[2])(int) = { addone, timestwo };  /* array[2] of ptr to fn(int)->int */
    printf("tab[0](5) = %d, tab[1](5) = %d\n", tab[0](5), tab[1](5));

    /* 5: pointer to array of function pointers */
    printf("\n=== Example 5: int (*(*ptab)[2])(int) ===\n");
    int (*(*ptab)[2])(int) = &tab;          /* ptr to array[2] of ptr to fn */
    printf("(*ptab)[1](7) = %d\n", (*ptab)[1](7));

    /* 6: const char * vs char * const */
    printf("\n=== Example 6: where const lands ===\n");
    char buf[] = "hello";
    const char *rp = buf;    /* pointer to const char: can't change *rp   */
    char *const cp = buf;    /* const pointer to char: can't change cp    */
    cp[0] = 'H';             /* legal: chars are writable through cp      */
    printf("rp reads: %s | cp wrote: %s\n", rp, buf);

    /* 7: reading char (*(*x[3])())[5] in stages */
    printf("\n=== Example 7: build-up of a monster ===\n");
    printf("x               name\n");
    printf("x[3]            array[3] of\n");
    printf("*x[3]           ...pointer to\n");
    printf("(*x[3])()       ...function returning\n");
    printf("*(*x[3])()      ...pointer to\n");
    printf("(*(*x[3])())[5] ...array[5] of\n");
    printf("char ...        ...char\n");

    /* 8: mini English translator for a few canned patterns */
    printf("\n=== Example 8: canned dcl translations ===\n");
    const char *decls[] = {
        "int *f();", "int (*pf)();", "int *a[10];", "int (*a)[10];"
    };
    const char *english[] = {
        "f: function returning pointer to int",
        "pf: pointer to function returning int",
        "a: array[10] of pointer to int",
        "a: pointer to array[10] of int"
    };
    for (int i = 0; i < 4; i++)
        printf("%-16s => %s\n", decls[i], english[i]);

    /* 9: parenthesized grouping changes everything */
    printf("\n=== Example 9: same tokens, different meaning ===\n");
    char *(fnames[2]) = { "alpha", "beta" };  /* parens redundant here */
    printf("char *(fnames[2]) is still array of pointer: %s %s\n",
           fnames[0], fnames[1]);
    printf("but char (*fname2)[2] would be pointer to array[2] of char\n");

    return 0;
}

int getval(void)   { return 7; }
int getval2(void)  { return 8; }
char firstchar(void) { return 'A'; }
int addone(int x)   { return x + 1; }
int timestwo(int x) { return x * 2; }
