#include <stdio.h>

int main() {
    // Variable = a named storage box. Its a name that it job is to hold
    // and represent the value that was given or being asignt to it.
    // Variable = age , price , gpa , grade , name[] , is Student.

    // Format:
    //     [data type] [variable] = value;
    // Make a variable with this type, this name, and this value.    
    char grade = 'A';
    char name[] = "Hoang";

    int age = 25;
    short smallNumber = 100;
    long bigNumber = 8000000L;
    signed int temperature = -10;
    unsigned int count = 50;
    float price = 9.99f;
    double gpa = 3.75;
    bool isStudent = true;

    // Data type = tell C what kind of value the variable can store.
    //int = whole number
    //float = decimal
    //double = more precise decimal
    //char = one character
    //char[] = text/string
    //bool = true/false

    // [% ] Format placeholders = C needs placeholders because it needs to know how to print the variable.
    printf("Grade: %c\n", grade);               // %c    = char , variable's name inside (" ")
    printf("Name: %s\n", name);                 // %s    = string/text ,follow by , variable's name inside (" ")
    printf("Age: %d\n", age);                   // %d    = int , variable's name inside (" ")
    printf("Small number: %hd\n", smallNumber);
    printf("Big number: %ld\n", bigNumber);
    printf("Temperature: %d\n", temperature);
    printf("Count: %u\n", count);
    printf("Price: %.2f\n", price);             // %.2f  = decimal with 2 digits after decimal , variable's name inside (" ")
    printf("GPA: %.2f\n", gpa);
    printf("Is student: %d\n", isStudent);      // %d    = bool as 1 or 0 , variable's name inside (" ")

    return 0;
}