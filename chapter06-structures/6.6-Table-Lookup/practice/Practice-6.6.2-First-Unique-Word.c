/*
Practice 6.6.2 - First Unique Word + Frequency via Hash Table

Problem:
Read all words from stdin. Then answer, in one pass over stored data:
  1. the FIRST word that appeared exactly once ("first unique")
  2. the most frequent word (ties: whichever you meet first)
  3. total distinct words

    echo "cat dog cat bird dog cat fish" | ./uniq1
    first unique: bird
    most frequent: cat (3)
    distinct: 4

Requirements:
- Hash table with chaining; entry: { next, name, count, order } where
  order = sequence number of the word's FIRST appearance.
- Stream words with getword; lookup-or-install each; found -> count++.
- After EOF, scan the whole table: among count==1 entries pick min order;
  among all entries pick max count.
- Free everything at the end.

DSA/Algorithm Focus: hash map as frequency counter (the #1 interview pattern)
Best approach: O(1) average per word during the stream; O(d) final scan.
Complexity: O(W + d) total time, O(d) space, W words, d distinct.
Constraints: no sorting, no BST, no arrays of words - table only.

Hints (Socratic):
- Why must "order" be recorded at FIRST insert and never updated?
- Could you answer "first unique" during the stream instead of after?
  What extra structure would that need - is it worth it here?
- What does your program print when input is empty? Decide and handle it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXWORD 100

struct wentry {
    struct wentry *next;
    char *name;
    int count;
    int order;
};

unsigned hash(char *s);
struct wentry *lookup(char *s);
int getword(char *word, int lim);

int main(){
    // Student writes code here
    return 0;
}

unsigned hash(char *s){
    // Student writes code here
    return 0;
}

struct wentry *lookup(char *s){
    // Student writes code here
    return NULL;
}

int getword(char *word, int lim){
    // Student writes code here
    return 0;
}
