/*
Practice 01 - Cumulative Loop Challenge

Book Level:
K&R 1.1 through 3.5

Problem:
Build a simple number practice program.

The program should ask the user for:

* a starting number
* an ending number
* a menu choice

The user can choose what kind of numbers to print.

Menu:
1 - Print all numbers from start to end
2 - Print only even numbers from start to end
3 - Print only odd numbers from start to end
4 - Print the sum from start to end

Example:
Start: 1
End: 5
Choice: 4

Output:
Sum: 15

Program Requirements:

* Use scanf to get input.
* Use switch for the menu choice.
* Use a while loop or for loop.
* Use if statements when needed.
* Use arithmetic operators.
* Print clear output.
* Use comments to explain your loop.

Required Skills:

* printf
* scanf
* variables
* int
* arithmetic
* comparison operators
* if / else
* switch
* case
* break
* default
* while loop
* for loop
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

    int start;
    int end;
    int choice;
    int i;
    int sum = 0;
    int odd;

    printf("Menu:\n"
            "1 - Print all numbers from start to end\n"
            "2 - Print only even numbers from start to end\n"
            "3 - Print only odd numbers from start to end\n"
            "4 - Print the sum from start to end\n");
    printf("\nStart: ");
    scanf(" %d", &start);
    printf("End: ");
    scanf(" %d", &end);
    printf("Choice: ");
    scanf(" %d", &choice);

    switch (choice){
        case 1:
            for(i = start; i <= end; i++){
                printf("Number: %d\n", i);
                
            }break;

        case 2:
            for(i = start; i <= end; i++){
                if (i % 2 == 0){
                    printf("Even: %d\n", i);
                }
            }
            break;

        case 2:
            for(i = start; i <= end; i++){
                if (i % 2 != 0){
                    printf("Odd: %d\n", i);
            }
        }
        break;

        case 4:
            for(i = start; i <= end; i++){
                sum = sum + i;
            }
            printf("Sum: %d\n", sum);
            break;

        default:
            printf("Invalid choice.\n");


    }

    return 0;
}
