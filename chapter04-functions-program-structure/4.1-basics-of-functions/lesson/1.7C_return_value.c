#include <stdio.h>

int addNumbers(int a, int b) { // paremeter ( data type + variable)
    int sum = a + b;
    return sum;  // sum is an interger , so indtead of void, this function return int, which why its a int function.
}

int main() {
    printf("--- Return Value Function ---\n");

    int result;

    result = addNumbers(5, 3);  // parameter ( value of dt +v )

    printf("Result: %d\n", result);
    printf("Program finished.\n");

    return 0;
}