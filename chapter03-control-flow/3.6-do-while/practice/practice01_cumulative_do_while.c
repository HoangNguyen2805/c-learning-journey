/*
Practice 01 - Cumulative Do-While Challenge

Book Level:
K&R 1.1 through 3.6

Problem:
Build a simple ATM menu program.

The program starts with a balance of $100.00.

The menu should repeat until the user chooses to quit.

Menu:
1 - Check balance
2 - Deposit money
3 - Withdraw money
0 - Quit

Program Requirements:

* Use a do-while loop so the menu shows at least once.
* Use scanf to get the user's menu choice.
* Use switch to handle the menu choice.
* Use if / else to check valid deposits and withdrawals.
* Use double for money.
* Use arithmetic to update the balance.
* Use break inside each switch case.
* Use default for invalid menu choices.

Rules:

* Do not use arrays.
* Do not use functions yet.
* Do not use goto.
* Do not copy an answer.
* Try from memory first.

Expected behavior:

* Choice 1 prints the current balance.
* Choice 2 asks for deposit amount.

  * If amount is greater than 0, add it to balance.
  * Otherwise print invalid deposit.
* Choice 3 asks for withdrawal amount.

  * If amount is greater than 0 and not more than balance, subtract it.
  * Otherwise print invalid withdrawal.
* Choice 0 prints goodbye and stops.
  */

#include <stdio.h>

int main() {

    float balance = 100.00;
    int choice;
    float amount;

    do{
        printf("Menu:\n"
                "1 - Check balance\n"
                "2 - Deposit money\n"
                "3 - Withdraw money\n"
                "0 - Quit\n");
        printf("\nChoice: ");
        scanf(" %d", &choice);

        switch(choice){
            case 0:
                printf("Goodbye\n");
            break;

            case 1:
                printf("\nYour current balance is %.2f\n\n", balance);
            break;

            case 2:
                printf("How much would you like to deposite ?");
                scanf("%f", &amount);
                if(amount > 0 && amount <= balance){
                    balance = amount + balance;
                    printf("You current balance is now %.2f\n", balance);
                } else {
                    printf("Invalid deposit.\n");
                }
            break;

            case 3:
                printf("How much would like to withdrawal ?");
                scanf("%f", &amount);
                if(amount < balance){
                    balance = balance - amount;
                    printf("\nYou just withdrawal %.2f\n", amount);
                    printf("You current balance is now %.2f\n", balance);
                } else {
                    printf("invalid withdrawal.\n");
                }
            break;

            default:
                printf("Invalid choice! Try again.\n");
            break;
            

        }

    } while (choice != 0);

    return 0;
}