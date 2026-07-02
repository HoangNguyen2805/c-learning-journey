/*
Practice 4.8A - Cumulative: Number Classifier Using Block Scope

Book Level:
K&R 1.1 through 4.8 (block structure)

Classic DSA Problem:
Classify a series of numbers entered by the user into categories
(negative, zero, small positive, large positive), and report
category counts at the end.

THE BLOCK SCOPE TWIST (the actual point of this practice):
Each category's processing logic must use block-scoped variables
declared INSIDE the if/else if blocks themselves - not at the top
of the function. This forces you to practice declaring variables
exactly where they're needed, not "just in case" at the top.

Menu:
Keep reading numbers until the user enters 999 (sentinel value).
For each number:
- negative (< 0): print "Negative: [num]"
- zero (== 0): print "Zero"
- small positive (1-99): print "Small: [num]"
- large positive (>= 100): print "Large: [num]"

After 999 is entered, print a summary:
Negatives:       X
Zeros:           X
Small positives: X
Large positives: X
Total entered:   X  (not counting 999 itself)

THE BLOCK SCOPE REQUIREMENT:
Inside each if/else if branch, declare a block-scoped variable to
build the label string length (just a simple int tracking how many
digits the number has, computed using the / and % you know from Ch.2).

Example - inside the "negative" branch:
{
    int digits = 0;         // block-scoped, only exists here
    int temp = num;
    if (temp < 0) temp = -temp;  // make positive for counting
    while (temp > 0) {
        digits++;
        temp = temp / 10;
    }
    printf("Negative (%d digits): %d\n", digits, num);
}

This forces block-scope variable usage naturally, not artificially.

Example run:
Enter numbers (999 to stop):
-45
Negative (2 digits): -45
0
Zero
7
Small (1 digit): 7
250
Large (3 digits): 250
999

Summary:
Negatives:       1
Zeros:           1
Small positives: 1
Large positives: 1
Total entered:   4

Program Requirements:
* Use a while loop reading numbers until sentinel 999 (Ch.3).
* Use if / else if / else for classification (Ch.3).
* Declare block-scoped variables INSIDE each branch for digit counting
  (Ch.4.8 - the new concept).
* Use functions for the digit-counting logic (Ch.4.1):
  int countDigits(int num) -> returns how many digits num has
* Use external counters for the four category counts (Ch.4.3).
* Use prototypes above main (Ch.4.1).

Rules:
* Do not use arrays.
* Do not use goto.
* Try from memory first.
*/

#include <stdio.h>

int countDigits(int num);

int main() {
   int num;
   int negCount = 0;
   int zeroCount = 0;
   int smallCount = 0;
   int largeCount = 0;
   int total = 0;
   while (1){
      
      printf("\nEnter numbers (999 to stop): ");
      scanf("%d", &num);

      if (num == 999){
            printf("999\n");
            break;
      } else if (num < 0){
         int lessThanZero = num;
         negCount++;
         printf("Negative (%d digits): %d\n", countDigits(num), lessThanZero);
      } else if (num == 0){
         int zero = num;
         zeroCount ++;
         printf("Zero\n");
      } else if (num < 100){
         int smallNum = num;
         smallCount ++;
         printf("Small (%d digit): %d\n", countDigits(num) , smallNum);
      } else {
         int largeNum = num;
         largeCount ++;
         printf("Large (%d digit): %d\n", countDigits(num), largeNum);
      }
      total++;
   }

   printf("\nSummary:\n"
          "Negatives: %d\n"
          "Zeros: %d\n"
          "Small positives: %d\n"
          "Large positives: %d\n"
          "Total entered: %d\n", negCount, zeroCount, smallCount, largeCount, total);

    return 0;
}

int countDigits(int num){ // counting digit dsa
   int count = 0;
   while(num != 0){
      count++;
      num = num / 10;
   }
   return count;
}