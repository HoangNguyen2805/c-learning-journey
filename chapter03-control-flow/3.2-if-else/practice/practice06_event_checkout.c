/*
Practice 06 — Student Event Checkout System

Task

Ask user for:

name
age
hasID
hasTicket
ticketPrice
moneyPaid
quizScore

Rules:

Part 1: Entry check

Use nested if.

If age is 18 or older:

check if hasID is 1
if yes: print Entry age/ID check passed.
if no: print You are old enough, but you need ID.

Else:

print You are too young to enter alone.
Part 2: Ticket check

If user has ticket AND passed age/ID check:

print Ticket check passed.
Else:
print Ticket check failed.
Part 3: Payment check

Calculate:

change = moneyPaid - ticketPrice

If moneyPaid is greater than or equal to ticketPrice:

print Payment accepted.
print change with 2 decimals

Else:

print Not enough money.
Part 4: Quiz grade

Use else if:

90+ = A
80+ = B
70+ = C
below 70 = F
Part 5: Even or odd score

Use %.

If quizScore is even:

print Score is even.

Else:

print Score is odd.

Example input:

Enter name: Hoang
Enter age: 20
Do you have ID? 1 yes, 0 no: 1
Do you have ticket? 1 yes, 0 no: 1
Enter ticket price: 12.50
Enter money paid: 20.00
Enter quiz score: 85

Expected output idea:

--- Student Event Checkout ---
Name: Hoang
Age: 20

Entry age/ID check passed.
Ticket check passed.
Payment accepted.
Change: $7.50
Grade: B
Score is odd.
Program finished.
Requirements

Use these:

char name[50]
int age
int hasID
int hasTicket
double ticketPrice
double moneyPaid
double change
int quizScore
scanf
printf
nested if
if / else
else if
&&
>=
-
%

Compile/run:

cd ~/c-learning-journey/01-c-basics/day05-conditions-if-else/practice
gcc practice06_event_checkout.c -o practice06_event_checkout
./practice06_event_checkout

*/

#include <stdio.h>

int main() {

    char name[50];
    int age;
    int hasID;
    int hasTicket;
    double ticketPrice;
    double moneyPaid;
    double change;
    int quizScore;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Do you have ID? 1 yes, 0 no: ");
    scanf("%d", &hasID);

    printf("Do you have ticket? 1 yes, 0 no: ");
    scanf("%d", &hasTicket);

    printf("Enter ticket price: ");
    scanf("%lf", &ticketPrice);

    printf("Enter money paid: ");
    scanf("%lf", &moneyPaid);

    // change

    printf("Enter quiz score: ");
    scanf("%d", &quizScore);

    printf("\n--- Student Event Checkout ---\n");
    printf("\nName: %s\n", name);
    printf("Age: %d\n", age);

    // Part 1:
    if ( age >= 18) {
        if ( hasID == 1 ) {
            printf("Entry age/ID check passed.\n");
        } else {
            printf("You are old enough, but you need ID.\n");
        }
    } else {
        printf("You are too young to enter alone.\n");
    }

    // Part 2:
    if ( hasTicket == 1 && age >= 18 && hasID == 1 ) {
        printf("Ticket check passed.\n");
    } else {
        printf("Ticket check failed.\n");
    }

    // Part 3:
    if ( moneyPaid >= ticketPrice) {
        printf("Payment accepted.\n");
        change = moneyPaid - ticketPrice;
        printf("Change: $%.2lf\n", change);
    } else {
        printf("Not enough money.\n");
    }

    // Part 4:
    if ( quizScore >= 90) {
        printf("Grade: A\n");
    } else if ( quizScore >= 80 ) {
        printf("Grade: B\n");
    } else if ( quizScore >= 70 ) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }

    // Part 5:
    if ( quizScore % 2 == 0){
        printf("Score is even.\n");
    } else {
        printf("Score is odd.\n");
    }
    
    return 0;
}