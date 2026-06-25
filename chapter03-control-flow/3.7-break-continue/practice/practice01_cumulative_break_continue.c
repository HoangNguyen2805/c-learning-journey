/*
Practice 01 - Cumulative Break and Continue Challenge

Book Level:
K&R 1.1 through 3.7

Problem:
Build a simple number entry analyzer.

The program should repeat a menu until the user chooses to quit.

Menu:
1 - Process a batch of numbers
0 - Quit

If the user chooses 1:

* Ask how many numbers they want to enter.
* Use a for loop to read that many numbers.
* If the user enters a negative number, skip it using continue.
* If the user enters 0, stop reading numbers early using break.
* If the number is positive, add it to a total sum.
* Count how many positive numbers were accepted.
* Count how many accepted numbers were even.
* Count how many accepted numbers were odd.

Important:

* Negative numbers should NOT be added.
* Negative numbers should NOT count as even or odd.
* 0 should stop the loop early.
* 0 should NOT be added.
* 0 should NOT count as even or odd.

Example:
How many numbers? 5

Enter number 1: 4
Enter number 2: -8
Negative number skipped.
Enter number 3: 7
Enter number 4: 0
Zero entered. Stopping early.

Output:
Accepted numbers: 2
Even numbers: 1
Odd numbers: 1
Sum: 11

Program Requirements:

* Use a do-while loop for the menu.
* Use switch for the menu choice.
* Use a for loop to process the batch of numbers.
* Use if / else-if / else.
* Use continue to skip negative numbers.
* Use break to stop early when the user enters 0.
* Use break in the switch cases.
* Use default for invalid menu choices.
* Print clear output.

Required Skills:

* printf
* scanf
* variables
* int
* arithmetic
* comparison operators
* logical thinking
* if / else-if / else
* switch
* case
* default
* do-while
* for loop
* break
* continue
* comments

Rules:

* Do not use arrays.
* Do not use functions yet.
* Do not use goto.
* Do not copy an answer.
* Try from memory first.
  */

#include <stdio.h>

int main() {

  int choice;
  int quantity;
  int number;
  


  do {

    printf("\nMenu:\n"
          "1 - Process a batch of numbers\n"
          "0 - Quit\n");
    printf("Enter: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("\nHow many number you want to enter ?");
        scanf("%d", &quantity);

        int accepted = 0;
        int even = 0;
        int odd = 0;
        int sum = 0;
        for ( int i = 1; i <= quantity ; i++ ){
          printf("\nEnter number %d:", i);
          scanf("%d", &number);

          if(number < 0){
            printf("Negative number skipped.\n");
            continue;
          } else if (number == 0) {
            printf("Zero entered. Stopping early.\n");
            break;
          } else {
              accepted++;
              
              if(number %2 == 0){
              even++;
            } else {
              odd++;
            }
            sum = sum + number;
          }
        }
        printf("\nOutput:\n");
        printf("Accepted numbers: %d\n", accepted);
        printf("Even number: %d\n", even);
        printf("Odd number: %d\n", odd);
        printf("Sum: %d\n", sum);
        break;

      case 0:
      printf("Quitting\n");
      break;

      default:
      printf("Invalid choice, try again!\n");
      break;
    }

  } while (choice != 0);

  return 0;
}