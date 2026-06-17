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