#include <stdio.h>

int main() {

    int age;
    int hasID;
    int hasCash;
    int hasCard;
    int isRaining;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Do you have ID? Type 1 for yes, 0 for no: ");
    scanf("%d", &hasID);

    printf("Do you have cash? Type 1 for yes, 0 for no: ");
    scanf("%d", &hasCash);

    printf("Do you have card? Type 1 for yes, 0 for no: ");
    scanf("%d", &hasCard);

    printf("Is it raining? Type 1 for yes, 0 for no: ");
    scanf("%d", &isRaining);

    printf("\n--- Logical Operator Results ---\n");

    if (age >= 18 && hasID == 1) {            // && means AND
        printf("You can enter.\n");           // Both conditions must be true.
    } else {                                  // If not (both wrong or 1 of them is wrong)
        printf("You cannot enter.\n");        // It'll be false
    }

    if (hasCash == 1 || hasCard == 1) {       // || means OR
        printf("You can pay.\n");             // At least one condition must be true.(or both)
    } else {                                  // If not (both of them are wrong)
        printf("You cannot pay.\n");          // It'll be false
    }

    if (!isRaining) {                         // ! means NOT
        printf("You can go outside.\n");      // It flips true/false. (Turn True into False)
    } else {                                  // If not. (Turn False into True)
        printf("Bring an umbrella.\n");       // It'll be false
    }

    return 0;
}

/*
## Lesson 05E - Logical Operators

Logical operators combine or flip conditions.

&& means AND.
Both sides must be true.

Example:
age >= 18 && hasID == 1

This is true only if:
age is 18 or older
AND
hasID is 1

|| means OR.
At least one side must be true.

Example:
hasCash == 1 || hasCard == 1

This is true if:
hasCash is 1
OR
hasCard is 1
OR both are 1

! means NOT.
It flips true and false.

Example:
!isRaining

If isRaining is 0, then !isRaining is true.
If isRaining is 1, then !isRaining is false.

In C:
0 = false
non-zero = true

*/