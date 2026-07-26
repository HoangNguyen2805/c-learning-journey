/*
Practice 5.3.2 — String Reversal (using pointers)
Write a function that reverses a string in-place using two pointers (one at start, one at end). Classic DSA pattern.
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

void reverseString(char *arr, int size);
void swap(char *a, char *b);

int main() {

    char arr[100];
    printf("REVERSING STRING!!\n");
    printf("Enter your String: ");
    scanf(" %[^\n]", arr);
    
    // count how many element is in the array
    int size = 0;
    while(arr[size] != '\0'){
        size++;
    }

    // reversing
    reverseString(arr, size);

    // Displace preversed output
    printf("REVERSED STRING: %s\n", arr);

    return 0;
}

void reverseString(char *arr, int size){
    char *startPointer = &arr[0];       // left
    char *endPointer = &arr[size - 1];  // right

    while(startPointer < endPointer){
        // swapping
        swap(startPointer, endPointer);
        // move pointer
        startPointer++; // move 1 to the right
        endPointer--;   // move 1 to the left
    }
}

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}