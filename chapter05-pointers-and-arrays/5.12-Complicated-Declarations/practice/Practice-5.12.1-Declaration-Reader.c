/*
Practice 5.12.1 - Declaration Reader (simplified dcl)  [FROM K&R - 5.12]

Problem:
Convert simple C declarations to English, one per input line:

    input:  int *daytab[13]
    output: daytab: array[13] of pointer to int

    input:  char (*p)()
    output: p: pointer to function returning char

Support: one base type word (int/char/double/void), *'s, one identifier,
[] with optional size, (), and ONE level of grouping parentheses.

Requirements:
- Implement K&R's structure:
      int  gettoken(void);          // returns NAME, PARENS, BRACKETS, or char
      void dcl(void);               // handles *'s, then dirdcl, appends "pointer to"
      void dirdcl(void);            // name | ( dcl ) | suffix ()/[] loop
- Globals (K&R style): token, tokentype, name[], datatype[], out[].
- Build the English into out[] with strcat; print "name: out datatype".
- On a syntax error, print a message and keep going with the next line.

DSA/Algorithm Focus: recursive-descent parsing (grammar -> mutually recursive functions)
Best approach: one function per grammar rule; lookahead of a single token.
Complexity: O(n) over input length; recursion depth = paren nesting depth.
Constraints: MAXTOKEN 100, MAXOUT 1000; no dynamic memory.

Hints (Socratic):
- Which grammar rule makes dirdcl call dcl? What input character triggers it?
- Why must "pointer to" be appended AFTER the recursive call returns?
- What should gettoken do with whitespace? With a digit inside [ ]?
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXOUT   1000

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
void dcl(void);
void dirdcl(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXOUT];

int main(){
    // Student writes code here
    return 0;
}

int gettoken(void){
    // Student writes code here
    return 0;
}

void dcl(void){
    // Student writes code here
}

void dirdcl(void){
    // Student writes code here
}
