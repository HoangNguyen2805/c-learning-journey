/*
6.8A - Unions: worked examples
Compile: gcc -Wall -Wextra -o 6.8A 6.8A_unions.c
*/
#include <stdio.h>
#include <string.h>

union u_tag {
    int ival;
    float fval;
    char *sval;
};

enum vtype { T_INT, T_FLOAT, T_STRING };

struct variant {                 /* the tagged union pattern */
    enum vtype type;
    union u_tag u;
};

void print_variant(const struct variant *v);

int main(void)
{
    /* 1: one space, many hats */
    printf("=== Example 1: union basics ===\n");
    union u_tag u;
    u.ival = 42;
    printf("as int: %d\n", u.ival);
    u.fval = 3.14f;
    printf("as float: %.2f (ival is now garbage)\n", u.fval);

    /* 2: size = largest member */
    printf("\n=== Example 2: sizeof union vs struct ===\n");
    struct s_all { int i; float f; char *s; };
    printf("union: %zu bytes, struct with same members: %zu bytes\n",
           sizeof(union u_tag), sizeof(struct s_all));

    /* 3: members overlap - same address */
    printf("\n=== Example 3: members share an address ===\n");
    printf("&u.ival=%p\n&u.fval=%p  <- identical\n",
           (void *)&u.ival, (void *)&u.fval);

    /* 4: reading the wrong member = nonsense */
    printf("\n=== Example 4: last-written rule ===\n");
    u.ival = 100;
    printf("wrote ival=100; fval reads as %g <- meaningless bits\n", u.fval);

    /* 5: the tagged union - safe usage */
    printf("\n=== Example 5: tagged union ===\n");
    struct variant a, b, c;
    a.type = T_INT;    a.u.ival = 7;
    b.type = T_FLOAT;  b.u.fval = 2.5f;
    c.type = T_STRING; c.u.sval = "hello";
    print_variant(&a);
    print_variant(&b);
    print_variant(&c);

    /* 6: array of variants - heterogeneous list! */
    printf("\n=== Example 6: mixed-type array via tagged union ===\n");
    struct variant items[3] = {
        { T_STRING, { .sval = "count:" } },
        { T_INT,    { .ival = 3 } },
        { T_FLOAT,  { .fval = 9.81f } }
    };
    for (int i = 0; i < 3; i++)
        print_variant(&items[i]);

    /* 7: unions copy as a unit */
    printf("\n=== Example 7: union assignment ===\n");
    union u_tag u2 = u;              /* raw copy of the shared bytes */
    printf("u2.ival = %d (copied from u)\n", u2.ival);

    /* 8: initialization targets the FIRST member */
    printf("\n=== Example 8: initializer rule ===\n");
    union u_tag u3 = { 99 };         /* goes to ival (first member) */
    printf("u3 initialized {99} -> ival=%d\n", u3.ival);
    union u_tag u4 = { .fval = 1.5f };  /* C99 designated: any member */
    printf("designated init -> fval=%.1f\n", u4.fval);

    /* 9: inspection demo - float bits via unsigned (educational only) */
    printf("\n=== Example 9: peeking at float bits (type punning) ===\n");
    union { float f; unsigned int bits; } peek;
    peek.f = 1.0f;
    printf("1.0f stored as bits: 0x%08X (impl-dependent - demo only)\n",
           peek.bits);

    return 0;
}

void print_variant(const struct variant *v)
{
    switch (v->type) {
    case T_INT:
        printf("[int]    %d\n", v->u.ival);
        break;
    case T_FLOAT:
        printf("[float]  %g\n", v->u.fval);
        break;
    case T_STRING:
        printf("[string] %s\n", v->u.sval);
        break;
    }
}
