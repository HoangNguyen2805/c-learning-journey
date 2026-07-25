/*
Practice 7.1.1 - Letter Frequency Histogram (filter)

Problem:
Read ALL of stdin; print a horizontal histogram of letter frequencies
(case-insensitive):

    ./histo < essay.txt
    a: ######## 8
    b: ## 2
    ...
    z:  0

Requirements:
- One getchar loop; tolower each alphabetic char; tally in int freq[26].
- Which index does letter c get? Derive it from 'a' - no magic numbers.
- Scale: if the max count exceeds 60, print counts scaled so the longest
  bar is exactly 60 #'s (integer math: bar = freq[i] * 60 / max).
- Print the numeric count after each bar; skip nothing - all 26 rows.

DSA/Algorithm Focus: counting array (frequency table) - the direct-address map
Best approach: O(n) single pass + O(26) render.
Complexity: O(n + 26) time, O(26) space.
Constraints: input may be empty (max would be 0 - guard the division!).

Hints (Socratic):
- Why is freq[26] enough - what property of 'a'..'z' makes direct
  addressing work?
- Where must the tolower happen relative to the isalpha test? Does order matter?
- What is bar length for freq=1, max=100? Is losing it to 0 acceptable -
  or should nonzero counts always show at least one #? Decide + implement.
*/

#include <stdio.h>
#include <ctype.h>

int main(){
    // Student writes code here
    return 0;
}
