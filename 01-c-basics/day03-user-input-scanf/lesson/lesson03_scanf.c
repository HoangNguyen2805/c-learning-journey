/*
        What is scanf ?
    We have already learn that data type and variable can hold value , and
we able to asign value into it. Then inorder to displace that value in terminal,
we have to use printf with data plave holder to displace it as an output. Everything
have to be done by the programer, BUT what if the user want to asign value them self
as an input ?
    - We will use scanf to allow use input the own data.
            printf = print/output
            scanf = scan/read/input
    Today we let the user type the value.
Example:
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Your age is %d\n", age);

Meaning:
    int age; = create an empty variable named age
    printf = ask the user a question
    scanf = read what the user types
    &age = store the typed value inside age

Common scanf formats
    int      -> scanf("%d", &age);
    float    -> scanf("%f", &price);
    double   -> scanf("%lf", &gpa);
    char     -> scanf(" %c", &grade);
    char[]   -> scanf("%s", name);

For double, scanf uses:
    scanf("%lf", &gpa);
For printf, double can use:
    printf("%f\n", gpa);

char[] does not use &
    char name[50];
    scanf("%s", name);
Not:
    scanf("%s", &name);
Remember: 
    normal variables use &
    arrays/strings usually do not use &

    The format of scanf and ALMOST the same but NOT EXACTLY the same as printf , where 
    - printf = printf("text + placeholder", variable);
    But 
    - scanf = scanf("%d", &age);

    You CAN put text inside scanf, but usually you should not when learning.
    Notice: scanf can contain text, but it is not used for normal prompts.
If text is inside scanf, the user input must match that text exactly.
Better habit: use printf to ask, then scanf to read.
    Why ?
    Ex:
    scanf("Age: %d", &age);
    The user must LITERALLY type -> Age: 25 
    Istead of just -> 25
    scanf expecte user to type -> Age: <- first.

    BUT other than that, THE ONLY DIFFERENT that printf doesn't have that scanf have is
            &
        next to the variable. What is & and why it's important ?
    Why does scanf need &?
        - Because scanf needs to know WHERE THE VARIABLE LIVES IN MEMORY so it can change
        the value inside it.
    Think:
        printf only looks at the value.
        scanf needs to put a new value into the variable.
    SO & is like a poiter that point the user's inut to the correct Variable.
    
One important char rule
    Use a space before %c:
        scanf(" %c", &grade);
    - The space helps skip leftover Enter/newline from previous input.
    */

#include <stdio.h>

int main() {
    int age;      // Since we want to to asign to this variable by user's input.
    float price;  // We stiull have to declare it here
    char grade;   // But we don't have asign any value.

    // Inorder to help the user Understand what to input, We have to create a promt
    // to guild the user use using printf.
    printf("Enter your age: "); // We dont use \n in this case because we want the
    // user to incert thier in put in the same row a a question so it look better.
    // As long as we don't use \n the next thing it prrint will be next to the previous
    // and stay at the same row.
    scanf("%d", &age);

    printf("Enter a price: ");
    scanf("%f", &price);            // scanf does not need \n to know when to stop

    printf("Enter your grade: ");
    scanf(" %c", &grade);

    printf("\n---result---\n");
    printf("Age: %d\n", age);
    printf("Price: %.2f\n", price);
    printf("Grade: %c\n", grade);

    return 0;
}

/*
input buffer
Ex:
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter a price: ");
    scanf("%f", &price);

    printf("Enter your grade: ");
    scanf("%c", &grade);

Output:
Enter your age: 25
Enter a price: 9.99
Enter your grade: 
---result---
Age: 25
Price: 9.99
Grade: 

Why can't we enter grade ? 
- Because of in put buffer in this line -> scanf("%c", &grade);
After you typed price 9.99 and pressed Enter, that Enter key is
still waiting in the input buffer. %c reads that Enter instead of waiting for A.

To Fix this adding space in front of %c
That space means: skip whitespace like Enter, spaces, tabs then read the character

Fix from this:
    scanf("%c", &grade);
To This:
    scanf(" %c", &grade);

Simple memory rule
%d, %f, %lf = skip whitespace automatically
%c = does not skip whitespace unless you put a space before it
So:
scanf("%d", &age);      // okay
scanf("%f", &price);    // okay
scanf(" %c", &grade);   // use space before %c
*/