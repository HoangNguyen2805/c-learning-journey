/*
Practice 4.3A - Cumulative External Variables (No Arrays)

Book Level:
K&R 1.1 through 4.3 (external variables, no arrays)

Problem:
Build a simple score tracker for a single player using a menu.

Use an EXTERNAL VARIABLE (declared outside all functions) to store
the player's running score. Multiple functions must read and modify
this same external variable directly - not through parameters or
return values.

Menu:
1 - Add points
2 - Subtract points
3 - Show current score
4 - Reset score
0 - Quit

External variables required:
* int score;        (starts at 0)
* int actionCount;  (starts at 0)

Functions required (all touch the external score DIRECTLY - no score
parameter, and the score-changing functions should be void):
* void addPoints(int amount)
* void subtractPoints(int amount)
* void showScore(void)
* void resetScore(void)

Special rules:
* Before subtracting, check if score - amount would go below zero.
  If so, print "Cannot go below zero." and use continue to skip back
  to the menu WITHOUT calling subtractPoints.
* If the user enters an invalid menu choice, print "Invalid choice."
  using default.
* actionCount increases by 1 for every successful add/subtract/reset
  (not for "show score" and not for invalid/rejected attempts).
* Print actionCount when the user quits.

Example:
Menu:
1 - Add points
2 - Subtract points
3 - Show score
4 - Reset score
0 - Quit
Enter choice: 1
Enter amount: 10
Score is now: 10

Enter choice: 2
Enter amount: 20
Cannot go below zero.

Enter choice: 3
Current score: 10

Enter choice: 0
Total actions performed: 1
Quitting.

Program Requirements:
* Declare score and actionCount as EXTERNAL variables (Ch.4.3).
* Functions directly read/modify the externals - no parameters or
  return values used FOR THE SCORE ITSELF (Ch.4.3).
* Use a do-while menu loop (Ch.3).
* Use switch with default (Ch.3).
* Use continue for the negative-score guard (Ch.3).
* Use if/else for the negative check (Ch.2/3).
* Use void functions where appropriate (Ch.4.1).

Rules:
* Do not use arrays.
* Do not use pointers.
* Do not use goto.
* Try from memory first.
*/

#include <stdio.h>

int score = 0;
int ationCount = 0;

int main() {

    int choice;

    do {
        printf("Menu:\n"
                "1 - Add points\n"
                "2 - Subtract points\n"
                "3 - Show current score\n"
                "4 - Reset score\n"
                "0 - Quit\n");

        
    } while (choice != 0);

    return 0;
}