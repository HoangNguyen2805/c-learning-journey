/*
Practice 5.4.2 — Reverse Array (Dynamic)
Take user input array size, dynamically allocate, read values, reverse using two pointers (pointer subtraction), print reversed, free memory.
*/
/*
COMPLEXITY ANALYSIS
Aspect	         Value	        Why
Time	         O(n)	        Loop through n elements once to read, once to reverse, once to print = 3n = O(n)
Space	         O(n)	        Allocate array of n integers = O(n) heap memory
Reversing only	 O(n/2) = O(n)	Swap loop runs n/2 times (meet in middle)
*/
/*
FLOW DIAGRAM
main()
  |
  +-- Get array size from user
  |
  +-- Allocate memory with malloc()
  |
  +-- Loop: Read integers into array
  |
  +-- Call reverseArray(arr, size)
  |       |
  |       +-- Create left and right pointers
  |       |
  |       +-- WHILE (left < right)
  |       |       |
  |       |       +-- Call swap(left, right)
  |       |       |
  |       |       +-- Move pointers
  |       |
  |       +-- Return
  |
  +-- Print reversed array
  |
  +-- Call free(arr) to deallocate
  |
  +-- Done!
*/
/*
MAIN:
  1. Declare int size
  2. Print "Enter array size:"
  3. Read size with scanf
  
  4. Allocate memory: arr = malloc(size * sizeof(int))
  5. Check if malloc succeeded (arr != NULL)
  
  6. Loop i from 0 to size-1:
       Print "Enter element [i]:"
       Read integer into arr[i]
  
  7. Call reverseArray(arr, size)
  
  8. Print "Reversed array:"
  9. Loop i from 0 to size-1:
       Print arr[i]
  
  10. Free memory: free(arr)
  11. Return 0

reverseArray(int *arr, int size):
  1. Create leftPointer pointing to arr[0]
  2. Create rightPointer pointing to arr[size - 1]
  
  3. While leftPointer < rightPointer:
       Call swap(leftPointer, rightPointer)
       Move leftPointer forward (leftPointer++)
       Move rightPointer backward (rightPointer--)

swap(int *a, int *b):
  1. Create int temp
  2. temp = *a
  3. *a = *b
  4. *b = temp
*/

#include <stdio.h>
#include <stdlib.h>

void reverseString(char *arr, int size);
void swap(char *a, char *b);

int main(){

    // input the size
    int size;
    printf("REVERSE String.\n");
    printf("How Long is your string ? - ");
    scanf(" %d", &size);
    printf(" character long.\n");

    // generate a dynamic memory that fit the user input's string
    char *arr = malloc(size * sizeof(char));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // collecting user input
    printf("Enter Your String: ");
    scanf(" %[^\n]", arr);

    // reversing
    reverseString(arr, size);

    // print output
    printf("REVESED String: %s\n", arr);

    // returning dynamic memory back
    free(arr);
    // set to NULL after free
    arr = NULL;

    return 0;
}
// reversing function
void reverseString(char *arr, int size){
    char *startPointer = &arr[0];        //left
    char *endPointer = &arr[size - 1];   // right

    while(startPointer < endPointer){ // keep swapping until the left index no long smaller than right index mean we reach the middle
        // swaping left to right, and right to left
        swap(startPointer, endPointer);

        startPointer++; // move 1 to the right
        endPointer--;   // move 1 to the left
    }
}
// swapping function
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*
There still a bug, If user want to enter 7 character long and user acually enter more than 7 character then it will create critical issue — 
buffer overflow!

to precen this we use for loop to collect use input 
```c
for(int i = 0; i < size; i++) {
    scanf("%c", &arr[i]);
    if(arr[i] == '\n') {
        arr[i] = '\0';  // Replace newline with null terminator
        break;
    }
}
```
even in this case use enter 2 character per loop %c only take one character , the first one.
*/