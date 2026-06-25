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

int main() {

    int choice;

    do{
        int i;
        int j;

        printf("\nMenu:\n"
               "1 - Search for target product\n"
               "0 - Quit\n"
               "You chose:");
        scanf("%d", &choice);
        
        if (choice == 1){
            int targetNumber;
            int a;
            int b;

            printf("Target: ");
            scanf(" %d", &targetNumber);
            printf("a = ");
            scanf(" %d", &a);
            printf("b = ");
            scanf(" %d", &b);

            for(i = 1; i <= a; i++){
                for(j = 1; j <= b; j++){
                    if(i * j == targetNumber){
                        goto found;
                    }
                }
            }
        
        printf("\nNo pair found!\n");
        goto search_done;
             
        }else if (choice == 0) {
            printf("Quiting!\n");
            break;

        } else {
            printf("Invalid choice, try again !");
            break;
        }

        found:
        printf("Pair: (%d * %d)\n", i, j);

        search_done:
        ;
        } while (choice != 0);

        

    return 0;
}
/*
this is exactly where nested loops are used.

The reason is because you have two changing numbers:

a changes
b changes

You are trying every possible pair:

a * b

So the algorithm is:

Show the menu.
If user chooses search, ask for:
target
max value for a
max value for b
Start a at 1.
For this a, start b at 1.
Check:
a * b == target
If it matches, print the pair and stop searching.
If it does not match, increase b.
Keep checking b until b passes maxB.
Then increase a.
Reset b back to 1.
Keep going until a passes maxA.
If no pair is found, print “not found.”

Example:

target = 12
maxA = 5
maxB = 5

The search goes like:

a = 1:
1*1, 1*2, 1*3, 1*4, 1*5

a = 2:
2*1, 2*2, 2*3, 2*4, 2*5

a = 3:
3*1, 3*2, 3*3, 3*4  ← found

When it finds 3 * 4 == 12, you use goto to jump out of both loops at once.

That is the whole reason this practice uses goto: because normal break would only leave the inner loop, but goto can jump completely outside both loops.
*/