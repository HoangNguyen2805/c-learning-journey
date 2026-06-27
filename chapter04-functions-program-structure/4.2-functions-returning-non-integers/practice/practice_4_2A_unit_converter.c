/*
Practice 4.2A - Cumulative Unit Converter with Non-Integer Returns

Book Level:
K&R 1.1 through 4.2

Problem:
Build a unit converter program using a menu that repeats until the user quits.

Menu:
1 - Celsius to Fahrenheit
2 - Fahrenheit to Celsius
3 - Average of two numbers
4 - Letter grade from a score
0 - Quit

For options 1-3, ask the user for the needed number(s) as a double.
For option 4, ask the user for a score as an int.

Functions required:
* double celsiusToFahrenheit(double c)   -> returns c * 9.0/5.0 + 32.0
* double fahrenheitToCelsius(double f)   -> returns (f - 32.0) * 5.0/9.0
* double average(double a, double b)     -> returns (a + b) / 2.0
* char letterGrade(int score)            -> returns 'A'/'B'/'C'/'F' based on score

Special rules:
* If the user enters an invalid menu choice, print "Invalid choice, try again."
  using default.
* For option 4 (letter grade), if the score is below 0 or above 100,
  print "Invalid score." and use continue to skip back to the menu
  WITHOUT calling letterGrade.
* After every valid conversion/calculation (options 1-3), print the result
  using %.2f (two decimal places) so it reads cleanly.
* Keep a running count of how many valid operations were performed
  (count options 1-4 only when they actually produced output — not
  invalid menu choices or invalid scores). Print this count when quitting.

Example:
Menu:
1 - Celsius to Fahrenheit
2 - Fahrenheit to Celsius
3 - Average
4 - Letter grade
0 - Quit
Enter choice: 1
Enter Celsius temperature: 100
Result: 212.00 F

Enter choice: 4
Enter score: 150
Invalid score.

Enter choice: 4
Enter score: 85
Grade: B

Enter choice: 0
Total operations performed: 2
Quitting.

Program Requirements:
* Use a do-while loop for the menu (Ch.3).
* Use switch with default for invalid menu choice (Ch.3).
* Use continue to skip an invalid score back to the menu (Ch.3).
* Use if/else if/else inside letterGrade to determine the grade (Ch.2/3).
* Write four functions with correct non-int return types (Ch.4.2):
  celsiusToFahrenheit (double), fahrenheitToCelsius (double),
  average (double), letterGrade (char).
* Declare matching prototypes above main() (Ch.4.1/4.2).
* Use %.2f for printing double results, %c for printing the char grade.
* Use a counter variable for valid operations performed.

Required Skills:
* printf, scanf (Ch.1)
* int, double, arithmetic, comparison operators (Ch.2)
* if / else, switch, case, default, do-while, continue (Ch.3)
* functions, parameters, return values, prototypes (Ch.4.1)
* functions returning double and char, return type matching prototype (Ch.4.2)

Rules:
* Do not use arrays.
* Do not use pointers.
* Do not use global/external variables.
* Do not use goto.
* Try from memory first.
*/

#include <stdio.h>

double CtoF (double c);
double FtoC (double f);
double average (double a, double b);
char letterGrade (double grade);

int main() {

    int choice;
    int count = 0;

    do {

        double c;
        double f;
        double a;
        double b;
        double grade;

        printf("\n\nMenu:\n"
                "1 - Celsius to Fahrenheit\n"
                "2 - Fahrenheit to Celsius\n"
                "3 - Average of two numbers\n"
                "4 - Letter grade from a score\n"
                "0 - Quit\n"
                "Choice: ");
        scanf("%d", &choice);
        

        switch(choice){
            case 0:
                    printf("Total operations performed: %d\n", count);
                    printf("Quitting.\n");
                break;

            case 1:
                printf("\nEnter in Celsius temperature: ");
                scanf("%lf", &c);
                printf("Result: %.2lf F\n", CtoF (c));
                count++;
                break;

            case 2:
                printf("\nEnter in Fahrenheit temperature: ");
                scanf("%lf", &f);
                printf("Result: %.2lf C\n", FtoC (f));
                count++;
                break;

            case 3:
                printf("\nEnter first number: ");
                scanf("%lf", &a);
                printf("Enter second number: ");
                scanf("%lf", &b);
                printf("Result: %.2lf\n", average (a,b));
                count++;
                break;

            case 4:
                printf("\nEnter score: ");
                scanf("%lf", &grade);
                if (grade < 0 || grade > 100){
                    printf("Invalid score.\n");
                    continue;
                }
                printf("Your grade is %c\n", letterGrade (grade));
                count++;
                break;


            default:
                printf("\nInvalid choice, try again!");
                break;
        } 
        
    } while (choice != 0);

    return 0;
}

double CtoF (double c){
    double f;
    f = c * 9.0/5.0 + 32.0;
    return f;
}

double FtoC (double f){
    double c;
    c = (f - 32.0) * 5.0/9.0;
    return c;
}

double average (double a, double b){
    return (a + b) / 2.0;
}

char letterGrade (double grade){
    if (grade > 90){
        return 'A';
    } else if (grade > 80) {
        return 'B';
    } else if (grade > 70) {
        return 'C';
    } else if (grade > 60) {
        return 'D';
    } else {
        return 'F';
    }
}