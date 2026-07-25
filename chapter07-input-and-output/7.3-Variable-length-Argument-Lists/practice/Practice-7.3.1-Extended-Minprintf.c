/*
Practice 7.3.1 - Extended minprintf  [FROM K&R - 7.3 + Exercise 7-3]

Problem:
Write minprintf from scratch, then extend it beyond the book:

Required conversions:
  %d int   %f double   %s string   %c char   %x int as hex   %% literal
Plus TWO features:
  %b  - print an int in binary (reuse your 7.2.2 to_binary thinking)
  field width for %d and %s: e.g. %8d, %-8s (parse the digits yourself
  with atoi-like accumulation while scanning; '-' flag for left justify)

Test in main with at least 6 calls covering every feature, including
width+flag combos and a format ending in a lone '%'.

Requirements:
- Only putchar for output of formatted values - do NOT call printf on the
  values (build padding/digit output yourself). Exception: you may build
  the digits of %d/%x into a small char buf and emit with putchar loop.
- va_arg types must respect promotions.

DSA/Algorithm Focus: lexer/state machine over a format string; manual
integer-to-string conversion (repeated %10 and /10 - reverse the digits!)
Best approach: parse spec into (leftflag, width), fetch arg, render into
a buffer, pad to width, emit. O(len + args).
Complexity: O(output length); buffer O(32).
Constraints: no sprintf; handle negative %d; hex digits via "0123456789abcdef".

Hints (Socratic):
- Digits generate LOW to HIGH order via %10. Where do you reverse?
- Padding: spaces go before or after the value depending on what flag?
  How many spaces exactly - width minus WHAT?
- What should %b do with 0? (Empty output is a bug - why?)
*/

#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main(){
    // Student writes code here
    return 0;
}

void minprintf(char *fmt, ...){
    // Student writes code here
}
