/*
Practice 5.10.2 - Grep Lite  [FROM K&R - based on the "find" program, 5.10]

Problem:
Read lines from standard input and print each line that contains the pattern
given on the command line:

    ./greplite main < mycode.c

Optional flags BEFORE the pattern:
    -n   print line numbers before matching lines
    -x   invert: print lines that do NOT contain the pattern

    ./greplite -n -x hello < input.txt
    ./greplite -nx hello  < input.txt      (combined flags must also work)

Requirements:
- Parse flags with the K&R idiom: while (--argc > 0 && (*++argv)[0] == '-')
- After flags, exactly one pattern must remain; otherwise print usage.
- Write your own mygetline(char line[], int max) and mystrindex(char s[], char t[])
  (you built these in earlier chapters - rebuild from memory).
- Match lines with mystrindex(line, pattern) >= 0, then apply the -x inversion.

DSA/Algorithm Focus: substring search (naive pattern matching) + flag parsing
Best approach: naive scan - for each position i in line, try to match pattern.
Complexity: O(n*m) per line where n = line length, m = pattern length; O(n) space.
Constraints: no <string.h> functions for the matching itself; MAXLINE 1000.

Hints (Socratic):
- In (*++argv)[0], which pointer moves? In *++argv[0], which one moves?
- Why does the flag loop decrement argc as it consumes arguments?
- What should (found != except) express, and why is it cleaner than four if-branches?
*/

#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int mystrindex(char source[], char searchfor[]);

int main(int argc, char *argv[]){
    // Student writes code here
    return 0;
}

int mygetline(char line[], int max){
    // Student writes code here
    return 0;
}

int mystrindex(char source[], char searchfor[]){
    // Student writes code here
    return -1;
}
