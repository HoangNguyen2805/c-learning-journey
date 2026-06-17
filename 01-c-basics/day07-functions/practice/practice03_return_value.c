/*
Practice 03 — Return Value Function

Make a student grade system that handles multiple students.

This practice uses:

printf
scanf
char name[50]
int
double
math
if / else if / else
for loop
functions
parameters
return values
void function
Program requirements

Ask the user:

How many students:

Then use a for loop to repeat for each student.

For each student, ask:

Enter name:
Enter score 1:
Enter score 2:
Enter score 3:

Then calculate:

total
average
grade
pass/fail count
Required functions

You must create these functions:

int addThreeScores(int a, int b, int c)

Returns the total score.

double calculateAverage(int total)

Returns the average.

void printGrade(double average)

Prints the grade:

90+ = Grade A
80+ = Grade B
70+ = Grade C
below 70 = Grade F
Pass / fail rule
average >= 70 = pass
average < 70 = fail

At the end, print:

Total passed:
Total failed:
Program finished.
Example input
How many students: 2

Enter name: Hoang
Enter score 1: 90
Enter score 2: 80
Enter score 3: 70

Enter name: Alex
Enter score 1: 50
Enter score 2: 60
Enter score 3: 70
Expected output
--- Student Result ---
Name: Hoang
Total: 240
Average: 80.00
Grade: B
Status: Pass

--- Student Result ---
Name: Alex
Total: 180
Average: 60.00
Grade: F
Status: Fail

Total passed: 1
Total failed: 1
Program finished.
Important hints

Your function definitions should look like this:

int addThreeScores(int a, int b, int c)

But when you call the function, do not write the types:

total = addThreeScores(score1, score2, score3);

For average:

average = calculateAverage(total);

For grade:

printGrade(average);
Compile and run
cd ~/Desktop/c-learning-journey/01-c-basics/day07-functions/practice
gcc practice03_return_value.c -o practice03_return_value
./practice03_return_value

*/

#include <stdio.h>

double calculateAverage(int total) {
    total = score1 + score2 +score3
} return total;
int main() {

    int studentCount;
    int score1;
    int score2;
    int score3;
    char name[50];


    printf("How many students: ");
    scanf("%d", studentCount);

    for (int i = 1; i <= studentCount; i++) {
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter score 1: ");
        scanf("%d", &score1);

        printf("Enter score 2: ");
        scanf("%d", &score2);

        printf("Enter score 3: ");
        scanf("%d", &score3);

        printf("\n--- Student Result---\n");
        printf("Name: %s", name);
    
    }
    
    return 0;
}