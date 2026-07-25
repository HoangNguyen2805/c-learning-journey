/*
Practice 5.12.2 - undcl: English back to C  [FROM K&R - Exercise 5-18 area]

Problem:
The reverse of Practice 5.12.1. Read a line like:

    input:  x () * [] * char
    output: char (*(*x())[])()

Format of input (K&R's simplification): a name, then a sequence of tokens
read LEFT to RIGHT describing the type inside-out:
    ()   = function returning
    []   = array of         ([13] = array[13] of)
    *    = pointer to
ending with the base type word.

Requirements:
- Reuse your gettoken() from 5.12.1.
- Build the output string outward: when you see *, wrap current string
  in "(* ... )" ONLY if the next token is () or [] (precedence!);
  otherwise a bare "*" prefix is enough.
- Print: basetype + " " + built-string.

DSA/Algorithm Focus: string building with precedence-aware wrapping
Best approach: iterative token loop; sprintf into a temp buffer, swap buffers.
Complexity: O(n * L) where L is current string length per wrap; fine for MAXOUT 1000.
Constraints: same globals/limits as 5.12.1.

Hints (Socratic):
- WHY does *x() need parens as (*x)() but **x needs none? Which rule from
  the lesson decides?
- What lookahead do you need before deciding to wrap? (peek one token)
- Trace "x () * [] * char" by hand FIRST - what is the string after each token?
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXOUT   1000

enum { NAME, PARENS, BRACKETS };

int gettoken(void);

int tokentype;
char token[MAXTOKEN];

int main(){
    // Student writes code here
    return 0;
}

int gettoken(void){
    // Student writes code here
    return 0;
}
