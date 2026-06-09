/*
A Variable = a 'named box' that "Stores A Value".
A Data Type = a 'lable' on the box that says "what kind of thing (value) 
              can go inside (store) the Variable".
Ex: Create a variable named age that stores the whole number 25.
    int age = 25;

    Think:
        int = type of value (It's an Interger)
        age = variable name
        25 = value store inside Variable (age)

When you use printf, you need the correct placeholder for the data type. We don't write
    out raw date number, we use:
        ("%__, age");
    to displace the raw data number or value that have store in specific variable, and 
    to dis place the correct value of that specific variable we comma and add the variable
    within the (" ").

    Ex: printf needs placeholders:
        int      -> %d
        float    -> %f
        double   -> %f
        char     -> %c
        char[]   -> %s
        bool     -> %d

Basic data types:
1. int = Stores whole numbers.
    Ex:
        int age = 25;
        int year = 2026;
        int score = -10;
    Use %d to print:
        printf("Age: %d\n", age);

2. float = Stores decimal numbers (6-7 digits AFTER the decimal).
    Ex:
        float price = 9.99;
        float temperature = 98.6;
    Use %f to print:
        printf("Price: %f\n", price);
    Usually we use %.2f to show 2 decimal places:
        printf("Price: %.2f\n", price);
            Output:
            Price: 9.99
3. double = Stores decimal numbers with more precision than float (15-16 digits AFTER the decimal).
    Ex:
        double gpa = 3.754321;
        double pi = 3.1415926535;
    Use %f or %lf in printf:
        printf("GPA: %.2f\n", gpa);

    float = decimal
    double = more accurate decimal

4. char = Stores ONLY 1 Charcter in a SINGlE ' ' (NOT DOUBLE " ")
    Ex:
        char grade = 'A';
        char letter = 'h';
        char symbol = '$';
    Use %c to print:
        printf("Grade: %c\n", grade);
    Important:
        char grade = 'A';      // correct
        char grade = "A";      // wrong for char

Modified integer ( int ) types - These are variations of whole numbers.
5. short = Stores smaller whole numbers ( same as int but only SMALL number with FEWER Digits).
    Ex:
        short smallNumber = 100;
    Use %hd:
        printf("%hd\n", smallNumber);

6. long = Stores biger whole number than int.
    Ex:
        long population = 8000000000;
    Use %ld:
        printf("%ld\n", population);

7. long long = Stores very big whole numbers.
    Ex:
        long long bigNumber = 9000000000000;
    Use %lld:
        printf("%lld\n", bigNumber);

Positive-only integer types
8. unsigned int = Stores only zero or positive whole numbers.
    Ex:
        unsigned int count = 50;
    Use %u:
        printf("%u\n", count);
    Meaning: Meaning:

Boolean type
9. bool = Stores true or false.
    To use bool, we have to # this header:
        #include <stdbool.h>
    Example:
        #include <stdio.h>
        #include <stdbool.h>

        int main() {
            bool isPassing = true;

            printf("Is passing: %d\n", isPassing);

            return 0;
        }
    Output:
        Is passing: 1

    In C:
        true = 1
        false = 0

Text / string 
10. char[] = In C, we store string like text and sentence or multiple character
             As An ARRAY.
    Ex:
        char name[] = "Hoang";
    Print with %s:
        printf("Name: %s\n", name);

    Important:
        char = one character
            Ex: char grade = 'A';
        char[] = text/string
            Ex: char name[] = "Hoang";

Special type
11. void = Means “no value.” USe in naming function.
    Ex:
        void sayHello() {
            printf("Hello\n");
        }
    Meaning:
        This function does not return a value.
        */

#include <stdio.h>
#include <stdbool.h>

int main() {
    // Variable = a named storage box. Its a name that it job is to hold
    //and represent the value that was given or being asignt to it.
    // Variable = age , price , gpa , grade , name[] , is Student.

    // Format:
    //      type name = value;
    // Make a variable with this type, this name, and this value.
    int age = 25;
    float price = 9.99;
    double gpa = 3.75;

    // Data type = tell C what kind of value the variable can store.
    //int = whole number
    //float = decimal
    //double = more precise decimal
    //char = one character
    //char[] = text/string
    //bool = true/false


    char grade = 'A';
    char name[] = "Hoang";
    bool isStudent = true;

    // Format placeholders = C needs placeholders because it needs to know how to print the variable.
    printf("Name: %s\n", name);                      // %s    = string/text ,follow by , variable's name inside (" ")
    printf("Age: %d\n", age);                        // %d    = int , variable's name inside (" ")
    printf("Price: %.2f\n", price);                  // %.2f  = decimal with 2 digits after decimal , variable's name inside (" ")
    printf("GPA: %.2f\n", gpa);                      //
    printf("Grade: %c\n", grade);                    // %c    = char , variable's name inside (" ")
    printf("Is student: %d\n", isStudent);           // %d    = bool as 1 or 0 , variable's name inside (" ")

    return 0;
}

/*
Compile and run
In terminal:
cd ~/c-learning-journey/01-c-basics/day02-variables-data-types/lesson

gcc lesson02_variables.c -o lesson02

./lesson02

Output:

Name: Hoang
Age: 25
Price: 9.99
GPA: 3.75
Grade: A
Is student: 1
*/