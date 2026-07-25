/*
6.5A - Self-referential Structures: worked examples (BST word counter)
Compile: gcc -Wall -Wextra -o 6.5A 6.5A_self_referential_structures.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void);
char *dupstr(const char *s);
struct tnode *addtree(struct tnode *p, const char *w);
void treeprint(const struct tnode *p);
int treesize(const struct tnode *p);
int treeheight(const struct tnode *p);
const struct tnode *treefind(const struct tnode *p, const char *w);
void treefree(struct tnode *p);

int main(void)
{
    struct tnode *root = NULL;

    /* 1: a node that points to its own type */
    printf("=== Example 1: the self-referential shape ===\n");
    printf("sizeof(struct tnode) = %zu bytes (word,count,left,right)\n",
           sizeof(struct tnode));
    printf("left/right are POINTERS - that's why the size is finite\n");

    /* 2: grow a tree from a word stream */
    printf("\n=== Example 2: building via addtree ===\n");
    const char *text[] = { "the","quick","brown","fox","the","lazy",
                           "dog","the","fox" };
    int n = sizeof text / sizeof text[0];
    for (int i = 0; i < n; i++)
        root = addtree(root, text[i]);
    printf("inserted %d words\n", n);

    /* 3: in-order traversal prints sorted */
    printf("\n=== Example 3: treeprint (in-order = alphabetical) ===\n");
    treeprint(root);

    /* 4: duplicates only bump count */
    printf("\n=== Example 4: duplicates ===\n");
    printf("\"the\" appeared 3 times in input - check the line above.\n");

    /* 5: search follows the invariant */
    printf("\n=== Example 5: treefind ===\n");
    const struct tnode *hit = treefind(root, "fox");
    printf("find \"fox\": %s (count=%d)\n",
           hit ? "found" : "missing", hit ? hit->count : 0);
    printf("find \"cat\": %s\n",
           treefind(root, "cat") ? "found" : "NULL - not in tree");

    /* 6: recursive size */
    printf("\n=== Example 6: treesize (distinct words) ===\n");
    printf("distinct words = %d\n", treesize(root));

    /* 7: recursive height */
    printf("\n=== Example 7: treeheight ===\n");
    printf("height = %d (balanced would be ~log2 of %d)\n",
           treeheight(root), treesize(root));

    /* 8: why dupstr matters */
    printf("\n=== Example 8: why we copy the word ===\n");
    char buffer[16];
    strcpy(buffer, "alpha");
    struct tnode *r2 = addtree(NULL, buffer);
    strcpy(buffer, "OVERWRITTEN");       /* reuse the buffer */
    printf("buffer now \"%s\" but node still \"%s\" - dupstr saved it\n",
           buffer, r2->word);

    /* 9: degenerate tree from sorted input */
    printf("\n=== Example 9: sorted input = worst case ===\n");
    struct tnode *chain = NULL;
    const char *sorted[] = { "a","b","c","d","e" };
    for (int i = 0; i < 5; i++)
        chain = addtree(chain, sorted[i]);
    printf("5 sorted inserts -> height %d (a linked list in disguise!)\n",
           treeheight(chain));

    /* 10: free everything (post-order) */
    printf("\n=== Example 10: treefree ===\n");
    treefree(root);
    treefree(r2);
    treefree(chain);
    printf("all nodes and words freed (children before parent)\n");

    return 0;
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *dupstr(const char *s)
{
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

struct tnode *addtree(struct tnode *p, const char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        if (p == NULL) {
            fprintf(stderr, "addtree: out of memory\n");
            exit(1);
        }
        p->word = dupstr(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(const struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int treesize(const struct tnode *p)
{
    if (p == NULL)
        return 0;
    return 1 + treesize(p->left) + treesize(p->right);
}

int treeheight(const struct tnode *p)
{
    if (p == NULL)
        return 0;
    int lh = treeheight(p->left);
    int rh = treeheight(p->right);
    return 1 + (lh > rh ? lh : rh);
}

const struct tnode *treefind(const struct tnode *p, const char *w)
{
    int cond;
    while (p != NULL) {
        if ((cond = strcmp(w, p->word)) == 0)
            return p;
        p = (cond < 0) ? p->left : p->right;
    }
    return NULL;
}

void treefree(struct tnode *p)
{
    if (p != NULL) {
        treefree(p->left);
        treefree(p->right);
        free(p->word);
        free(p);
    }
}
