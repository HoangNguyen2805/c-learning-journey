#include <stdio.h>

int main() {

    int age;
    int hasID;
    int score;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Do you have ID? 1 yes, 0 no: ");
    scanf("%d", &hasID);

    printf("Enter score: ");
    scanf("%d", &score);

    printf("\n--- Nested if Example ---\n");

    /*
    Main idea:

    nested if = if inside another if

    First check age.
    If age is okay, then check ID.

    else if order matters:
    check 90 before 80 before 70
    */

    if (age >= 18) {
        if (hasID == 1) {
            printf("You can enter.\n");
        } else {
            printf("You are old enough, but you need ID.\n");
        }
    } else {
        printf("You are too young.\n");
    }

    printf("\n--- else if order example ---\n");

    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }

    printf("Program finished.\n");

    return 0;
}