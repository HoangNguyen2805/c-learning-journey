/*
6.2A - Structures and Functions: worked examples
Compile: gcc -Wall -Wextra -o 6.2A 6.2A_structures_and_functions.c
*/
#include <stdio.h>

struct point { int x; int y; };
struct rect  { struct point pt1; struct point pt2; };

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);
void scale_copy(struct point p, int k);
void scale_ptr(struct point *pp, int k);
struct rect canonrect(struct rect r);
int rect_area(const struct rect *rp);

int main(void)
{
    /* 1: constructor function returning a struct */
    printf("=== Example 1: makepoint returns a struct ===\n");
    struct point a = makepoint(3, 4);
    printf("a = (%d,%d)\n", a.x, a.y);

    /* 2: building nested structs from calls */
    printf("\n=== Example 2: nested construction ===\n");
    struct rect screen;
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(640, 480);
    printf("screen (%d,%d)-(%d,%d)\n",
           screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);

    /* 3: pass by value - K&R addpoint mutates its own copy */
    printf("\n=== Example 3: addpoint (by value) ===\n");
    struct point b = makepoint(10, 20);
    struct point sum = addpoint(a, b);
    printf("a=(%d,%d) unchanged; sum=(%d,%d)\n", a.x, a.y, sum.x, sum.y);

    /* 4: proof that by-value cannot modify caller */
    printf("\n=== Example 4: by-value scaling changes nothing ===\n");
    scale_copy(a, 100);
    printf("after scale_copy(a,100): a=(%d,%d)  <- untouched\n", a.x, a.y);

    /* 5: pointer parameter DOES modify caller */
    printf("\n=== Example 5: pointer scaling works ===\n");
    scale_ptr(&a, 10);
    printf("after scale_ptr(&a,10):  a=(%d,%d)\n", a.x, a.y);

    /* 6: (*pp).x vs pp->x */
    printf("\n=== Example 6: arrow is sugar for (*p). ===\n");
    struct point *pp = &b;
    printf("(*pp).x = %d   pp->x = %d   (identical)\n", (*pp).x, pp->x);

    /* 7: K&R ptinrect */
    printf("\n=== Example 7: point-in-rectangle ===\n");
    struct point q = makepoint(100, 100);
    printf("q in screen? %s\n", ptinrect(q, screen) ? "yes" : "no");
    printf("(-5,-5) in screen? %s\n",
           ptinrect(makepoint(-5, -5), screen) ? "yes" : "no");

    /* 8: canonrect - normalize any corner pair */
    printf("\n=== Example 8: canonrect ===\n");
    struct rect wild = { {200, 300}, {50, 60} };
    struct rect fixed = canonrect(wild);
    printf("wild (%d,%d)-(%d,%d) -> canon (%d,%d)-(%d,%d)\n",
           wild.pt1.x, wild.pt1.y, wild.pt2.x, wild.pt2.y,
           fixed.pt1.x, fixed.pt1.y, fixed.pt2.x, fixed.pt2.y);

    /* 9: const pointer param - read-only efficiency */
    printf("\n=== Example 9: const struct pointer ===\n");
    printf("area(screen) = %d (passed by pointer, promised read-only)\n",
           rect_area(&screen));

    /* 10: precedence drill */
    printf("\n=== Example 10: ++p->x means ++(p->x) ===\n");
    struct point c = makepoint(7, 7);
    struct point *pc = &c;
    ++pc->x;
    printf("after ++pc->x: c=(%d,%d)  (x bumped, pointer NOT moved)\n", c.x, c.y);

    return 0;
}

struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;          /* safe: p1 is a private copy */
    p1.y += p2.y;
    return p1;
}

int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

void scale_copy(struct point p, int k)
{
    p.x *= k;              /* only the copy changes */
    p.y *= k;
}

void scale_ptr(struct point *pp, int k)
{
    pp->x *= k;
    pp->y *= k;
}

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

struct rect canonrect(struct rect r)
{
    struct rect temp;
    temp.pt1.x = MIN(r.pt1.x, r.pt2.x);
    temp.pt1.y = MIN(r.pt1.y, r.pt2.y);
    temp.pt2.x = MAX(r.pt1.x, r.pt2.x);
    temp.pt2.y = MAX(r.pt1.y, r.pt2.y);
    return temp;
}

int rect_area(const struct rect *rp)
{
    return (rp->pt2.x - rp->pt1.x) * (rp->pt2.y - rp->pt1.y);
}
