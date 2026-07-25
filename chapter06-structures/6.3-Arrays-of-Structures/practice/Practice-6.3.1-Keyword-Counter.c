/*
Practice 6.3.1 - C Keyword Counter  [FROM K&R - 6.3 main program]

Problem:
Count occurrences of C keywords in stdin (feed it a real .c file!):

    ./kwcount < 6.3A_arrays_of_structures.c

Requirements:
- struct key { char *word; int count; } keytab[] = { ... }; with AT LEAST
  15 keywords, alphabetically sorted; NKEYS via the sizeof trick.
- int getword(char *word, int lim): skip blanks; if first char is a letter,
  collect isalnum chars; otherwise return the char. Use getch/ungetch
  (your Ch4 pushback pair) or getc/ungetc.
- int binsearch(char *word, struct key tab[], int n): the O(log n) search.
- main: loop getword until EOF; if word[0] is a letter and binsearch hits,
  increment that row's count. At EOF print "count word" for count > 0.

DSA/Algorithm Focus: binary search over a sorted table + tokenization
Best approach: binary search per word - O(W log K) total for W words, K keywords.
Complexity: O(W log K) time, O(1) extra space.
Constraints: MAXWORD 100; table must stay sorted or search silently breaks.

Hints (Socratic):
- Why must getword PUSH BACK the character that ended a word?
- What goes wrong if "do" is listed after "double"? Test it.
- Where do comments and string literals confuse this counter? (Book exercise
  6-1 asks exactly this - optional stretch goal.)
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
    char *word;
    int count;
};

int getword(char *word, int lim);
int binsearch(char *word, struct key tab[], int n);

int main(){
    // Student writes code here
    return 0;
}

int getword(char *word, int lim){
    // Student writes code here
    return 0;
}

int binsearch(char *word, struct key tab[], int n){
    // Student writes code here
    return -1;
}
