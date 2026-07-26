/*
Practice 5.4.2 — Reverse Array (Dynamic)
Take user input array size, dynamically allocate, read values, reverse using two pointers (pointer subtraction), print reversed, free memory.
*/
/*
Can you implement the two-pointer version? The idea is still simple:

- Start pointer at beginning
- End pointer at end
- Swap them repeatedly as they move toward each other
- Stop when they meet
*/
/*
reverseString(char *s)
    |
    +-- Create left and right pointers
    |
    +-- WHILE (left < right)
    |       |
    |       +-- Call swap(left, right)  ← ONE swap
    |       |
    |       +-- Move pointers
    |
    +-- Done!


swap(char *a, char *b)
    |
    +-- Exchange *a and *b using temp variable
    |
    +-- Return
*/
#include <stdio.h>

int main() {

    char arr[] = "hello";



    return 0;
}

void reverseString(char *arr){
    int startPointer = arr[0];
    int endpointer;

}