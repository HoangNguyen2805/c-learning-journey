/*
Practice 03 — do while cumulative challenge.

Make a small menu using do while.

Ask the user to choose:

1. Print Hello
2. Print numbers 1 to 3
3. Exit

The menu should repeat until the user chooses 3.

Example run
--- Menu ---
1. Print Hello
2. Print numbers 1 to 3
3. Exit
Choose option: 1
Hello

--- Menu ---
1. Print Hello
2. Print numbers 1 to 3
3. Exit
Choose option: 2
1
2
3

--- Menu ---
1. Print Hello
2. Print numbers 1 to 3
3. Exit
Choose option: 3
Goodbye
Requirements

Use:

do while
scanf
if / else if / else
for loop inside option 2
int choice
Hint only
do {
    print menu
    scanf choice

    if choice is 1
        print Hello
    else if choice is 2
        use for loop to print 1 to 3
    else if choice is 3
        print Goodbye
    else
        print Invalid option

} while choice is not 3

For this practice, I want:

choice 1 → print Hello, then show the menu again
choice 2 → print 1 2 3, then show the menu again
choice 3 → print Goodbye, then stop

Compile/run:

cd ~/Desktop/c-learning-journey/01-c-basics/day06-loops/practice
gcc practice03_do_while_menu.c -o practice03_do_while_menu
./practice03_do_while_menu

*/

#include <stdio.h>

int main() {

    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Print Hello\n");
        printf("2. Print numbers 1 to 3\n");
        printf("3. Exit\n");
        printf("Enter: ");
        scanf("%d", &choice);

        if ( choice == 1) {
            printf("\nHello\n");
        } else if ( choice == 2) {
            for (int i = 1; i <= 3; i++){
                printf("\n%d\n", i);
            }
        } else if ( choice == 3){
            printf("\nGoodbye!?\n");
        } else {
            printf("\nInvalid option\n");
        }

    } while ( choice != 3);

    return 0;
}