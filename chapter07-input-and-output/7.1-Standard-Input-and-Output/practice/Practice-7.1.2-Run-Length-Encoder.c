/*
Practice 7.1.2 - Run-Length Encoder (streaming compression)

Problem:
Compress stdin with run-length encoding, streaming - never store the input:

    echo "aaabccccd" | ./rle     ->   a3b1c4d1

Rules:
- A run = consecutive identical characters. Output char then count.
- Newlines are characters too - encode them like any other (your output
  may look odd; that's fine and correct).
- Print a final newline of your own after EOF.
- Bonus symmetry check (write as a comment): could a decoder distinguish
  digits IN the data from your counts? What tweak would fix that?

Requirements:
- Track (prev char, run length); on change or EOF, emit the finished run.
- First character is a special case - there is no prev yet. Handle without
  duplicating the emit logic (hint: prev = EOF sentinel works - why?).

DSA/Algorithm Focus: streaming/online algorithm with O(1) state
Best approach: single pass; state machine of two variables.
Complexity: O(n) time, O(1) space - cannot do better.
Constraints: no arrays, no storing input; counts may exceed 9 (print %d).

Hints (Socratic):
- What EXACT moment do you emit a run - when it starts or when it ends?
  What event marks "it ended"?
- Why must there be one final emit AFTER the loop? What input proves it?
- Why is EOF a safe initial value for prev? Could 0 ('\0') ever be unsafe?
*/

#include <stdio.h>

int main(){
    // Student writes code here
    return 0;
}
