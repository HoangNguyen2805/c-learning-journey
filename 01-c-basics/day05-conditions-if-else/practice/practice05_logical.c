/*
Practice 05 — Logical Operators Challenge.

Ask the user for:

age
hasTicket
hasParent

Rules:

If age is 18 or older OR they have a parent, print:

Age rule passed.

Else print:

Age rule failed.

Then if they have a ticket AND age rule passed, print:

You can enter the event.

Else print:

You cannot enter the event.
Test 1

Input:

Enter age: 20
Do you have a ticket? 1 yes, 0 no: 1
Do you have a parent with you? 1 yes, 0 no: 0

Output:

Age rule passed.
You can enter the event.
Test 2

Input:

Enter age: 15
Do you have a ticket? 1 yes, 0 no: 1
Do you have a parent with you? 1 yes, 0 no: 1

Output:

Age rule passed.
You can enter the event.
Test 3

Input:

Enter age: 15
Do you have a ticket? 1 yes, 0 no: 1
Do you have a parent with you? 1 yes, 0 no: 0

Output:

Age rule failed.
You cannot enter the event.
Requirements

Use:

scanf
if / else
||
&&
int age
int hasTicket
int hasParent
int ageRulePassed

Compile/run:

cd ~/c-learning-journey/01-c-basics/day05-conditions-if-else/practice
gcc practice05_logical.c -o practice05_logical
./practice05_logical

*/

#include <stdio.h>

int main() {

    int age;

    int hasTicket;
    int hasParent;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Do you have a ticket? 1 yes, 0 no: ");
    scanf("%d", &hasTicket);

    printf("Do you have a parent with you? 1 yes, 0 no: ");
    scanf("%d", &hasParent);

    if ( age >= 18 || hasParent == 1 ) {
        printf("Age rule passed.\n");
    } else {
        printf("Age rule failed.\n");
    }

    if ( hasTicket == 1 && (age >= 18 || hasParent == 1) ) {
        printf("You can enter the event.\n");
    } else {
        printf("You cannot enter the event.\n");
    }

    return 0;

}

/*
// Usebool
#include <stdio.h>
#include <stdbool.h>

int main() {

    int age;

    int ticketInput;
    int parentInput;

    bool hasTicket = false;
    bool hasParent = false;

    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Do you have a ticket? 1 yes, 0 no: ");
    scanf("%d", &ticketInput);
    hasTicket = ticketInput;

    printf("Do you have a parent with you? 1 yes, 0 no: ");
    scanf("%d", &parentInput);
    hasParent = parentInput;

    if ( age >= 18 || hasParent == 1 ) {
        printf("Age rule passed.\n");
    } else {
        printf("Age rule failed.\n");
    }

    if ( hasTicket == 1 && (age >= 18 || hasParent == 1) ) {
        printf("You can enter the event.\n");
    } else {
        printf("You cannot enter the event.\n");
    }

    return 0;
}
*/