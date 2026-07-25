/*
8.7A - A Storage Allocator: K&R's malloc/free, runnable
Compile: gcc -Wall -Wextra -o 8.7A 8.7A_storage_allocator.c
Renamed my_malloc/my_free (the real ones are taken!) and built on a
static arena instead of sbrk (deprecated) - the ALGORITHM is identical;
my_morecore hands out slabs of the arena exactly as sbrk would.
*/
#include <stdio.h>
#include <string.h>

typedef long Align;                   /* for alignment to long boundary */

union header {                        /* block header */
    struct {
        union header *ptr;            /* next block if on free list */
        unsigned size;                /* size of this block         */
    } s;
    Align x;                          /* force alignment of blocks  */
};

typedef union header Header;

#define NALLOC 128                    /* minimum #units to request */
#define ARENA_UNITS 4096              /* our stand-in "OS memory"  */

static Header arena[ARENA_UNITS];    /* the pretend OS heap        */
static unsigned arena_used = 0;

static Header base;                   /* empty list to get started  */
static Header *freep = NULL;          /* start of free list         */

void *my_malloc(unsigned nbytes);
void my_free(void *ap);
static Header *my_morecore(unsigned nu);
void show_free_list(const char *label);

int main(void)
{
    /* 1: the Header union - alignment trick */
    printf("=== Example 1: the Header ===\n");
    printf("sizeof(Header)=%zu bytes = 1 'unit'; Align member forces it\n",
           sizeof(Header));

    /* 2: the nunits round-up formula */
    printf("\n=== Example 2: bytes -> units ===\n");
    for (unsigned b = 1; b <= 49; b += 16)
        printf("malloc(%2u bytes) -> %zu units (incl. header)\n",
               b, (b + sizeof(Header) - 1) / sizeof(Header) + 1);

    /* 3: first allocation builds the list and calls morecore */
    printf("\n=== Example 3: first malloc ===\n");
    char *a = (char *) my_malloc(40);
    printf("my_malloc(40) -> %p\n", (void *)a);
    show_free_list("after first malloc");

    /* 4: the header lives just below the user pointer */
    printf("\n=== Example 4: the hidden header ===\n");
    Header *ha = (Header *)a - 1;
    printf("header at %p says size=%u units\n", (void *)ha, ha->s.size);

    /* 5: several allocations carve the tail end */
    printf("\n=== Example 5: more mallocs ===\n");
    char *b = (char *) my_malloc(100);
    char *c = (char *) my_malloc(200);
    printf("b=%p c=%p (each carved from the free block's tail)\n",
           (void *)b, (void *)c);
    show_free_list("after three mallocs");

    /* 6: user memory works normally */
    printf("\n=== Example 6: using the memory ===\n");
    strcpy(a, "hello from my_malloc");
    printf("a contains: \"%s\"\n", a);

    /* 7: free returns a block; list grows */
    printf("\n=== Example 7: free(b) ===\n");
    my_free(b);
    show_free_list("after free(b)");

    /* 8: coalescing - free the neighbor, blocks MERGE */
    printf("\n=== Example 8: coalescing ===\n");
    my_free(c);
    show_free_list("after free(c) - b and c merged with arena tail?");
    printf("adjacent freed blocks fused into one bigger block\n");

    /* 9: reuse - next malloc first-fits into freed space */
    printf("\n=== Example 9: first-fit reuse ===\n");
    char *d = (char *) my_malloc(60);
    printf("my_malloc(60)=%p (compare with b=%p - recycled region!)\n",
           (void *)d, (void *)b);
    show_free_list("after reuse");

    my_free(a);
    my_free(d);
    show_free_list("after freeing everything (one big block again)");

    return 0;
}

/* K&R malloc: general-purpose storage allocator (corrected text) */
void *my_malloc(unsigned nbytes)
{
    Header *p, *prevp;
    unsigned nunits;

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {            /* no free list yet */
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {            /* big enough */
            if (p->s.size == nunits)          /* exactly    */
                prevp->s.ptr = p->s.ptr;
            else {                            /* allocate tail end */
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }
        if (p == freep)                       /* wrapped around free list */
            if ((p = my_morecore(nunits)) == NULL)
                return NULL;                  /* none left */
    }
}

/* morecore: ask "system" for more memory (arena stands in for sbrk) */
static Header *my_morecore(unsigned nu)
{
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;
    if (arena_used + nu > ARENA_UNITS)        /* sbrk == (char*)-1 case */
        return NULL;
    up = &arena[arena_used];                  /* cp = sbrk(nu * sizeof) */
    arena_used += nu;
    up->s.size = nu;
    my_free((void *)(up + 1));                /* insert via free! */
    return freep;
}

/* K&R free: put block ap in free list (corrected text) */
void my_free(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap - 1;                    /* point to block header */
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;              /* freed block at start or end of arena */

    if (bp + bp->s.size == p->s.ptr) {        /* join to upper nbr */
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) {                /* join to lower nbr */
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;
    freep = p;
}

/* debugging aid: walk and print the circular free list */
void show_free_list(const char *label)
{
    printf("  free list (%s): ", label);
    if (freep == NULL) {
        printf("(none)\n");
        return;
    }
    Header *p = freep;
    int guard = 0;
    do {
        printf("[%u]", p->s.size);
        p = p->s.ptr;
        if (p != freep) printf(" -> ");
    } while (p != freep && ++guard < 20);
    printf(" (circular)\n");
}
