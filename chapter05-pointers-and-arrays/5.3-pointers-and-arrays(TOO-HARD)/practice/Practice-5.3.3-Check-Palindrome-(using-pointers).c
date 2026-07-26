/*
Practice 5.3.3 — Check Palindrome (using pointers)
Write a function that checks if a string is a palindrome using two-pointer technique. Builds on string reversal.
*/
/*
isPalindrome(char *s, int size)
    |
    +-- Create left and right pointers
    |
    +-- WHILE (left < right)
    |       |
    |       +-- IF (*left != *right)
    |       |       |
    |       |       +-- Return 0 (NOT palindrome)
    |       |
    |       +-- Move pointers (left++, right--)
    |
    +-- Return 1 (IS palindrome)


main()
    |
    +-- Get user input
    |
    +-- Count string length
    |
    +-- Call isPalindrome(arr, size)
    |
    +-- IF result == 1
    |       |
    |       +-- Print "Is palindrome!"
    |
    +-- ELSE
    |       |
    |       +-- Print "Not palindrome!"
    |
    +-- Done!
*/
/*
MAIN:
  1. Declare char array[100]
  2. Print "Enter string:"
  3. Get user input with scanf
  4. Count the length (while loop until '\0')
  5. Call isPalindrome(array, length)
  6. Store result
  7. If result == 1:
       Print "Is palindrome!"
     Else:
       Print "Not palindrome!"
  8. Return 0

isPalindrome(char *arr, int size):
  1. Create startPointer pointing to arr[0]
  2. Create endPointer pointing to arr[size - 1]
  
  3. While startPointer < endPointer:
       If (*startPointer != *endPointer):
           Return 0  (characters don't match, not palindrome)
       
       Move startPointer forward (startPointer++)
       Move endPointer backward (endPointer--)
  
  4. If loop completes:
       Return 1  (all characters matched, is palindrome)
*/

#include <stdio.h>

int checkPalindrome(char *arr, int size);

int main(){

    // User input
    char arr[100];
    printf("PALINDROME checking.\n");
    printf("Example: (123321) , (abcddcba)\n");
    printf("Enter your: ");
    scanf(" %[^\n]", arr);

    //size of the array
    int size = 0;
    while(arr[size] != '\0'){
        size++;
    }

    // Checking
    checkPalindrome(arr, size);

    return 0;
}

int checkPalindrome(char *arr, int size){
    char *startPointer = &arr[0];       // left
    char *endPointer = &arr[size - 1];  // right

    while(startPointer < endPointer){
        if(*startPointer != *endPointer){
            printf("Not palindrome!\n");
            return 0;
        } else {
            startPointer++; // move 1 to the right
            endPointer--;   // move 1 to the left
        }
    }
    printf("Is palindrome!\n");
    return 1;
}
