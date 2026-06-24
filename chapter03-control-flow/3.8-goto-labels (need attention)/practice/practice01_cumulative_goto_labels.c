/*
Practice 01 - Cumulative Goto and Labels Challenge

Book Level:
K&R 1.1 through 3.8

Problem:
Build a simple target product finder.

The program should ask the user for:

* a target number
* a maximum value for a
* a maximum value for b

The program should search for the first pair:

a * b == target

Example:
Target: 12
Max a: 5
Max b: 5

The program checks:
1 * 1
1 * 2
1 * 3
...
2 * 1
2 * 2
2 * 3
2 * 4
2 * 5
3 * 1
3 * 2
3 * 3
3 * 4

When it finds:
3 * 4 == 12

It should print the pair and stop searching.

Important:
Use nested for loops.

Use goto to jump out of both loops when the pair is found.

Menu:
1 - Search for target product
0 - Quit

Program Requirements:

* Use a do-while loop for the menu.
* Use switch for the menu choice.
* Use nested for loops for the search.
* Use if to check if a * b equals the target.
* Use goto and a label to exit both loops early.
* Use break inside switch cases.
* Use default for invalid menu choices.
* Print clear output.

Required Skills:

* printf
* scanf
* variables
* int
* arithmetic
* comparison operators
* if
* switch
* case
* default
* do-while
* for loop
* break
* goto
* label
* comments

Rules:

* Do not use arrays.
* Do not use functions yet.
* Do not use goto everywhere.
* Use goto only to escape the nested loops.
* Try from memory first.

Important Note:
In real programs, goto should usually be avoided.

This practice uses goto because K&R 3.8 teaches it, and one reasonable use is escaping from nested loops.
*/

#include <stdio.h>

int main()
{
return 0;
}
