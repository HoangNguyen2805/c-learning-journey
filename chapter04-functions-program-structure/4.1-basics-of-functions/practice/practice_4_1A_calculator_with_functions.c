/*
Practice 4.1A - Cumulative Calculator with Functions

Book Level:
K&R 1.1 through 4.1

Problem:
Build a calculator program using a menu that repeats until the user quits.

The program must use separate FUNCTIONS to perform the math —
not inline calculations inside main().

Menu:
1 - Add two numbers
2 - Subtract two numbers
3 - Multiply two numbers
4 - Divide two numbers
0 - Quit

For options 1-4:
* Ask the user for two integers.
* Call the matching function (add, subtract, multiply, divide) to do the math.
* Print the result.

Special rules:
* If the user chooses Divide (4) and enters 0 as the second number,
  do NOT call the divide function. Print "Cannot divide by zero."
  and skip back to the menu using continue.
* If the user enters an invalid menu choice (not 0-4), print
  "Invalid choice, try again." using default in your switch.
* After every valid calculation, also report whether the RESULT
  was even or odd (reuse your even/odd logic from Chapter 3).
* Keep a running count of how many calculations were performed
  successfully (not counting divide-by-zero attempts or invalid menu choices).
  Print this count only when the user quits (choice == 0).

Example:
Menu:
1 - Add
2 - Subtract
3 - Multiply
4 - Divide
0 - Quit
Enter choice: 1
Enter first number: 10
Enter second number: 4
Result: 14
Result is even.

Menu:
...
Enter choice: 4
Enter first number: 9
Enter second number: 0
Cannot divide by zero.

Menu:
...
Enter choice: 0
Total calculations performed: 1
Quitting.

Program Requirements:
* Use a do-while loop for the menu (Ch.3).
* Use switch for the menu choice, with default for invalid input (Ch.3).
* Use continue to skip divide-by-zero back to the menu (Ch.3).
* Use if/else to check even/odd of the result (Ch.2/Ch.3).
* Write FOUR separate functions: add, subtract, multiply, divide —
  each takes two int parameters and returns an int (Ch.4.1).
* Declare function PROTOTYPES above main() (Ch.4.1).
* Define the actual functions AFTER main() (Ch.4.1).
* Use a counter variable to track successful calculations.
* Use comments explaining each part.

Rules:
* Do not use arrays.
* Do not use pointers.
* Do not use global/external variables — all data must pass through
  function parameters and return values.
* Do not use goto.
* Try from memory first.
*/

#include <stdio.h>


int add (int a , int b);
int subtract (int a , int b);
int multiply (int a , int b);
int divide (int a , int b);
void oddeven (int result);


int main() {

    int choice;
    int count = 0;

    do {
      int a;
      int b;
      int result;

      printf("\n\nMenu:\n"
             "1 - Add two numbers\n"
             "2 - Subtract two numbers\n"
             "3 - Multiply two numbers\n"
             "4 - Divide two numbers\n"
             "0 - Quit\n"
             "Enter choice: ");
      scanf(" %d", &choice);

      switch(choice){
        case 0:
            printf("Total calculations performed: %d\n", count);
            printf("Quitting.\n");
          break;

        case 1:
          printf("Enter first number: ");
          scanf("%d", &a);
          printf("Enter second number: ");
          scanf("%d", &b);
          result = add (a , b);
          printf("Result: %d\n", result);
          oddeven (result);
          count++;
          break;

        case 2:
          printf("Enter first number: ");
          scanf("%d", &a);
          printf("Enter second number: ");
          scanf("%d", &b);
          result = subtract (a , b);
          printf("Result: %d\n", result);
          oddeven (result);
          count++;
          break;

        case 3:
          printf("Enter first number: ");
          scanf("%d", &a);
          printf("Enter second number: ");
          scanf("%d", &b);
          result = multiply (a , b);
          printf("Result: %d\n", result);
          oddeven (result);
          count++;
          break;

        case 4:
          printf("Enter first number: ");
          scanf("%d", &a);
          printf("Enter second number: ");
          scanf("%d", &b);
          if (b == 0){
            printf("Cannot divide by zero.\n");
            continue;
          }
          result = divide (a , b);
          printf("Result: %d\n", result);
          oddeven (result);
          count++;
          break;

        default:
          printf("Invalid choice, try again !\n");
          break;
        
      }

    } while (choice != 0);

    return 0;
}

void oddeven (int result) {
  if (result % 2 == 0){
    printf("Result are even.\n");
  } else {
    printf("Result are odd.\n");
  }
}

int add (int a , int b) {
  return a + b;
}

int subtract (int a , int b) {
  return a - b;
}

int multiply (int a , int b) {
  return a * b;
}

int divide (int a , int b) {
  return a / b;
}