/*
Practice 6.6.1 - Mini #define Processor  [FROM K&R - 6.6 + Exercise 6-3 spirit]

Problem:
Read lines from stdin. Two command forms and free text:

    #define NAME replacement-text
    #undef NAME
    any other line

For a #define line: install(name, defn). For #undef: remove it.
For ANY other line: print it with every known NAME (as a standalone word)
replaced by its definition:

    #define PI 3.14
    area = PI * r * r        ->   area = 3.14 * r * r

Requirements:
- Full hash table: hash, lookup, install, undef - written from memory.
- Parse #define with sscanf or manual scanning; defn is REST of line.
- Replacement: use your getword-style scanning of the text line so that
  "PIN" does NOT match "PI" (whole-word matching only).
- mystrdup + malloc checks throughout; free the table before exit.

DSA/Algorithm Focus: hash table (chaining) as a symbol table + tokenized rewrite
Best approach: O(1) average lookup per word while streaming each line.
Complexity: O(L) per line of length L (each word hashed once); space O(defs).
Constraints: HASHSIZE 101; MAXWORD 100; MAXLINE 1000; no BST.

Hints (Socratic):
- Why does whole-word matching require tokenizing rather than strstr?
- Where does the newline live in your parsed defn? Should it?
- What should happen when a definition's replacement contains ANOTHER
  defined name? (K&R's real preprocessor recurses - decide + document.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXWORD 100
#define MAXLINE 1000

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
int undef(char *name);
char *mystrdup(char *s);

int main(){
    // Student writes code here
    return 0;
}
