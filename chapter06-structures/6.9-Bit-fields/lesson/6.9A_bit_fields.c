/*
6.9A - Bit-fields: worked examples
Compile: gcc -Wall -Wextra -o 6.9A 6.9A_bit_fields.c
*/
#include <stdio.h>

enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };   /* mask route */

struct sym_flags {                                    /* bit-field route */
    unsigned int is_keyword : 1;
    unsigned int is_extern  : 1;
    unsigned int is_static  : 1;
};

struct date_packed {
    unsigned int day   : 5;    /* 0..31  */
    unsigned int month : 4;    /* 0..15  */
    unsigned int year  : 12;   /* 0..4095 */
};

struct rgb565 {                /* classic embedded pixel format */
    unsigned int b : 5;
    unsigned int g : 6;
    unsigned int r : 5;
};

void show_flags_mask(unsigned f);

int main(void)
{
    /* 1: the mask idiom */
    printf("=== Example 1: masks - set, clear, test ===\n");
    unsigned flags = 0;
    flags |= EXTERNAL | STATIC;
    show_flags_mask(flags);
    flags &= ~STATIC;
    show_flags_mask(flags);
    printf("EXTERNAL set? %s\n", (flags & EXTERNAL) ? "yes" : "no");

    /* 2: same job with bit-fields */
    printf("\n=== Example 2: bit-fields - named bits ===\n");
    struct sym_flags sf = { 0, 0, 0 };
    sf.is_extern = sf.is_static = 1;
    printf("kw=%u ext=%u stat=%u\n", sf.is_keyword, sf.is_extern, sf.is_static);
    sf.is_static = 0;
    printf("after clear: stat=%u\n", sf.is_static);

    /* 3: space check */
    printf("\n=== Example 3: sizes ===\n");
    printf("3 ints would be %zu bytes; struct sym_flags is %zu\n",
           3 * sizeof(int), sizeof(struct sym_flags));

    /* 4: packed date - 21 bits of payload */
    printf("\n=== Example 4: packed date ===\n");
    struct date_packed d = { 24, 7, 2026 };
    printf("%02u/%02u/%u packed into %zu bytes (vs %zu as 3 ints)\n",
           d.day, d.month, d.year, sizeof d, 3 * sizeof(int));

    /* 5: field ranges */
    printf("\n=== Example 5: field range = 2^width - 1 ===\n");
    printf("day:5 bits max 31, month:4 bits max 15, year:12 bits max 4095\n");

    /* 6: silent overflow wrap */
    printf("\n=== Example 6: overflow wraps silently ===\n");
    d.day = 31;
    printf("day=31 ok: %u\n", d.day);
    d.day = (unsigned)32 & 0x1F;   /* what assignment of 32 becomes */
    printf("storing 32 into 5 bits -> %u (wrapped!)\n", d.day);

    /* 7: rgb565 pixel */
    printf("\n=== Example 7: RGB565 pixel format ===\n");
    struct rgb565 px;
    px.r = 31; px.g = 63; px.b = 0;              /* max red+green = yellow */
    printf("pixel r=%u g=%u b=%u in %zu bytes\n", px.r, px.g, px.b,
           sizeof px);

    /* 8: fields have no addresses */
    printf("\n=== Example 8: no & on fields ===\n");
    printf("&px    : %p  (whole struct: fine)\n", (void *)&px);
    printf("&px.r  : would NOT compile - bit-fields are not addressable\n");

    /* 9: comparing the two routes side by side */
    printf("\n=== Example 9: masks vs fields summary ===\n");
    printf("masks : portable layout, needs |= &= ~ idioms\n");
    printf("fields: readable, but packing order is implementation-defined\n");
    printf("rule  : external formats -> masks; internal packing -> fields\n");

    return 0;
}

void show_flags_mask(unsigned f)
{
    printf("flags=%03o (octal)  [kw=%d ext=%d stat=%d]\n", f,
           (f & KEYWORD) != 0, (f & EXTERNAL) != 0, (f & STATIC) != 0);
}
