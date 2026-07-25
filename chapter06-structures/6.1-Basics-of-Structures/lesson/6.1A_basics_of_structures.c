/*
6.1A - Basics of Structures: worked examples
Compile: gcc -Wall -Wextra -o 6.1A 6.1A_basics_of_structures.c -lm
*/
#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

void print_point(struct point p);
double dist_from_origin(struct point p);

int main(void)
{
    /* 1: define + member assignment */
    printf("=== Example 1: define and assign members ===\n");
    struct point pt;
    pt.x = 10;
    pt.y = 20;
    printf("pt = (%d, %d)\n", pt.x, pt.y);

    /* 2: initializer list */
    printf("\n=== Example 2: initialization ===\n");
    struct point maxpt = { 320, 200 };
    printf("maxpt = (%d, %d)\n", maxpt.x, maxpt.y);

    /* 3: members in expressions */
    printf("\n=== Example 3: members are ordinary variables ===\n");
    struct point p3 = { 3, 4 };
    printf("distance from origin = %.1f\n",
           sqrt((double)p3.x * p3.x + (double)p3.y * p3.y));

    /* 4: whole-structure copy */
    printf("\n=== Example 4: assignment copies everything ===\n");
    struct point a = { 1, 2 };
    struct point b = a;
    b.x = 99;
    printf("a = (%d,%d)   b = (%d,%d)  <- independent copies\n",
           a.x, a.y, b.x, b.y);

    /* 5: nested structures */
    printf("\n=== Example 5: nested struct (rect of two points) ===\n");
    struct rect screen = { { 0, 0 }, { 640, 480 } };
    printf("screen: (%d,%d) to (%d,%d)\n",
           screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);

    /* 6: computing with nested members */
    printf("\n=== Example 6: area from nested members ===\n");
    int area = (screen.pt2.x - screen.pt1.x) * (screen.pt2.y - screen.pt1.y);
    printf("area = %d pixels\n", area);

    /* 7: comparing structs must be member-wise */
    printf("\n=== Example 7: no == for structs ===\n");
    struct point c = { 1, 2 }, d = { 1, 2 };
    int same = (c.x == d.x && c.y == d.y);
    printf("c equals d? %s (compared member by member)\n", same ? "yes" : "no");

    /* 8: tagless one-off struct */
    printf("\n=== Example 8: tagless struct ===\n");
    struct { int hh; int mm; } t = { 14, 30 };
    printf("time = %02d:%02d (shape has no tag - one use only)\n", t.hh, t.mm);

    /* 9: passing a struct to a function (preview of 6.2) */
    printf("\n=== Example 9: struct as function argument ===\n");
    print_point(maxpt);
    printf("dist(maxpt) = %.1f\n", dist_from_origin(maxpt));

    return 0;
}

void print_point(struct point p)
{
    printf("point(%d, %d)\n", p.x, p.y);
}

double dist_from_origin(struct point p)
{
    return sqrt((double)p.x * p.x + (double)p.y * p.y);
}
