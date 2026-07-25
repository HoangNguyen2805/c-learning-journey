/*
6.7A - Typedef: worked examples
Compile: gcc -Wall -Wextra -o 6.7A 6.7A_typedef.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1: simple aliases */
typedef int Length;
typedef char *String;

/* 2: struct + typedef combos */
typedef struct point {
    int x, y;
} Point;

typedef struct tnode *Treeptr;
typedef struct tnode {
    char *word;
    int count;
    Treeptr left;
    Treeptr right;
} Treenode;

/* 3: function-pointer typedef */
typedef int (*PFI)(const char *, const char *);

/* 4: array typedef */
typedef int Row[4];

int numcmp_len(const char *a, const char *b);
Point mkpoint(int x, int y);

int main(void)
{
    /* 1: alias is the same type */
    printf("=== Example 1: Length is just int ===\n");
    Length len = 42;
    int plain = len;                    /* mixes freely - same type */
    printf("len=%d plain=%d sizeof(Length)=%zu\n", len, plain, sizeof(Length));

    /* 2: pointer alias */
    printf("\n=== Example 2: String is char* ===\n");
    String s = "hello typedef";
    printf("s = %s, first char = %c\n", s, *s);

    /* 3: struct without writing 'struct' */
    printf("\n=== Example 3: Point ===\n");
    Point p = mkpoint(3, 4);
    printf("p = (%d,%d), sizeof(Point)=%zu\n", p.x, p.y, sizeof(Point));

    /* 4: Treenode/Treeptr in action */
    printf("\n=== Example 4: Treenode via typedef ===\n");
    Treeptr root = (Treeptr) malloc(sizeof(Treenode));
    root->word = "root";
    root->count = 1;
    root->left = root->right = NULL;
    printf("root->word=%s (no 'struct tnode' spelled out)\n", root->word);
    free(root);

    /* 5: readable function pointers */
    printf("\n=== Example 5: PFI cleans up fn pointers ===\n");
    PFI cmp = strcmp;                    /* vs int (*cmp)(const char*, ...) */
    printf("cmp(\"apple\",\"banana\") = %d\n", cmp("apple", "banana") < 0 ? -1 : 1);
    cmp = numcmp_len;
    printf("by length: cmp(\"apple\",\"fig\") = %d\n", cmp("apple", "fig"));

    /* 6: array of function pointers - tamed */
    printf("\n=== Example 6: PFI table[] ===\n");
    PFI table[2] = { strcmp, numcmp_len };
    printf("table[0] and table[1] both callable: %d %d\n",
           table[0]("a", "a"), table[1]("ab", "a"));

    /* 7: array typedef */
    printf("\n=== Example 7: Row = int[4] ===\n");
    Row r1 = { 1, 2, 3, 4 };
    Row matrix[2] = { {1,2,3,4}, {5,6,7,8} };   /* 2x4 via typedef */
    printf("r1[2]=%d matrix[1][3]=%d sizeof(Row)=%zu\n",
           r1[2], matrix[1][3], sizeof(Row));

    /* 8: the #define trap, demonstrated safely */
    printf("\n=== Example 8: typedef beats #define for pointers ===\n");
    typedef int *IntPtr;
    IntPtr a2, b2;                       /* BOTH are int*            */
    int v1 = 10, v2 = 20;
    a2 = &v1; b2 = &v2;
    printf("*a2=%d *b2=%d (with #define Ptr int*, b2 would be int!)\n",
           *a2, *b2);

    /* 9: portability-style alias */
    printf("\n=== Example 9: portability aliases ===\n");
    typedef long Filesize;               /* one line to change per platform */
    Filesize fs = 1048576L;
    printf("Filesize fs = %ld (like size_t/ptrdiff_t in the library)\n", fs);

    return 0;
}

int numcmp_len(const char *a, const char *b)
{
    return (int)strlen(a) - (int)strlen(b);
}

Point mkpoint(int x, int y)
{
    Point t;
    t.x = x; t.y = y;
    return t;
}
