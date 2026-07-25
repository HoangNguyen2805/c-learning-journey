/*
5.11A - Pointers to Functions: worked examples
Compile: gcc -Wall -Wextra -o 5.11A 5.11A_pointers_to_functions.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int square(int n);
int cube(int n);
int numcmp(const char *s1, const char *s2);
int lencmp(const char *s1, const char *s2);
void apply(int arr[], int n, int (*f)(int));
void sort2(const char *v[], int n, int (*comp)(const char*, const char*));
int compose(int x, int (*f)(int), int (*g)(int));

int main(void)
{
    /* 1: declare, assign, call */
    printf("=== Example 1: basic function pointer ===\n");
    int (*fp)(int, int);
    fp = add;
    printf("via pointer: add(3,4) = %d\n", (*fp)(3, 4));
    printf("modern call syntax:    %d\n", fp(3, 4));

    /* 2: reassign to point elsewhere */
    printf("\n=== Example 2: reassignment ===\n");
    fp = sub;
    printf("same pointer, now sub(10,4) = %d\n", fp(10, 4));

    /* 3: function name vs function call */
    printf("\n=== Example 3: name = address, () = call ===\n");
    printf("address stored from 'add' : %p\n", (void*)add);
    printf("add(1,1) result           : %d\n", add(1, 1));

    /* 4: function pointer as parameter (higher-order function) */
    printf("\n=== Example 4: apply() maps a function over an array ===\n");
    int nums[] = {1, 2, 3, 4, 5};
    apply(nums, 5, square);
    printf("after square: ");
    for (int i = 0; i < 5; i++) printf("%d ", nums[i]);
    printf("\n");
    apply(nums, 5, cube);
    printf("after cube:   ");
    for (int i = 0; i < 5; i++) printf("%d ", nums[i]);
    printf("\n");

    /* 5: dispatch table (array of function pointers) */
    printf("\n=== Example 5: dispatch table ===\n");
    int (*ops[3])(int, int) = { add, sub, mul };
    const char *names[3] = { "add", "sub", "mul" };
    for (int i = 0; i < 3; i++)
        printf("%s(6,3) = %d\n", names[i], ops[i](6, 3));

    /* 6: K&R style - choose comparator at runtime */
    printf("\n=== Example 6: sort with pluggable comparator ===\n");
    const char *words[] = { "100", "25", "3", "9" };
    sort2(words, 4, (int (*)(const char*, const char*))strcmp);
    printf("as text:    ");
    for (int i = 0; i < 4; i++) printf("%s ", words[i]);
    printf("\n");
    sort2(words, 4, numcmp);
    printf("as numbers: ");
    for (int i = 0; i < 4; i++) printf("%s ", words[i]);
    printf("\n");

    /* 7: a second custom comparator - by string length */
    printf("\n=== Example 7: sort by length comparator ===\n");
    const char *animals[] = { "elephant", "cat", "zebra", "ox" };
    sort2(animals, 4, lencmp);
    printf("by length:  ");
    for (int i = 0; i < 4; i++) printf("%s ", animals[i]);
    printf("\n");

    /* 8: composing functions through pointers */
    printf("\n=== Example 8: compose f(g(x)) ===\n");
    printf("square(cube(2)) = %d\n", compose(2, square, cube));
    printf("cube(square(2)) = %d\n", compose(2, cube, square));

    /* 9: the declaration trap */
    printf("\n=== Example 9: declaration trap ===\n");
    printf("int (*p)(void)  -> pointer to function returning int\n");
    printf("int  *p (void)  -> FUNCTION returning pointer to int\n");
    printf("The parentheses around (*p) decide everything.\n");

    return 0;
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int square(int n)     { return n * n; }
int cube(int n)       { return n * n * n; }

/* strcmp-style contract on numeric string values (K&R numcmp) */
int numcmp(const char *s1, const char *s2)
{
    double v1 = atof(s1), v2 = atof(s2);
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

/* compare by length */
int lencmp(const char *s1, const char *s2)
{
    return (int)strlen(s1) - (int)strlen(s2);
}

/* apply f to each element in place */
void apply(int arr[], int n, int (*f)(int))
{
    for (int i = 0; i < n; i++)
        arr[i] = (*f)(arr[i]);
}

/* tiny insertion sort over pointer array, comparator injected */
void sort2(const char *v[], int n, int (*comp)(const char*, const char*))
{
    for (int i = 1; i < n; i++) {
        const char *key = v[i];
        int j = i - 1;
        while (j >= 0 && (*comp)(v[j], key) > 0) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

/* return f(g(x)) */
int compose(int x, int (*f)(int), int (*g)(int))
{
    return (*f)((*g)(x));
}
