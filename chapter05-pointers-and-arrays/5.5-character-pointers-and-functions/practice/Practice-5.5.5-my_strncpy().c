/*
Practice 5.5.5 — my_strncpy() (Bounded Copy)
Copy only first N characters (prevents buffer overflow)
Does NOT add null terminator (caller must do this)
Example: strncpy(dest, "hello world", 5) → copies "hello"
*/
//so copy from the first character to the limmit set by whoever
/*
PSEUDOCODE:
my_strncpy(char *dest, char *src, int n):
  1. Loop: while n > 0
    - *dest = *src (copy one character)
    - Move dest forward (dest++)
    - Move src forward (src++)
    - Decrement counter (n--)
  2. Done (caller must add '\0' if needed)

FLOWCHART:
my_strncpy(dest, src, n):
  |
  +-- WHILE (n > 0)
  |       |
  |       +-- *dest = *src (copy character)
  |       |
  |       +-- dest++
  |       |
  |       +-- src++
  |       |
  |       +-- n-- (decrement counter)
  |       |
  |       +-- Check condition again
  |
  +-- Return

EXAMPLE:
  my_strncpy(dest, "hello world", 5)
  - Loop 5 times
  - Copy: 'h', 'e', 'l', 'l', 'o'
  - Result: dest = "hello" (no null terminator)
  - dest[5] = '\0'  // Caller must add this

KEY: Copy exactly n characters, no null terminator added
*/
#include <stdio.h>

void my_strncpy(char *A, char *B, int n);

int main(){

    char arr[100];
    char dest[100];
    int unit;
    printf("Enter your string: ");
    scanf(" %[^\n]", arr);
    printf("How far from the begining you want to copy ? - ");
    scanf(" %d", &unit);
    printf("unit, from bigining of the string.\n");

    my_strncpy(dest, arr, unit); // void function doesnt return. cant be part of string
    /*
    After calling th fuintion, a new string have been store in dest, but
    that string can not be displace yet because we did not copy `\0` the NULL terminator.
    Without NULL terminator compiler doesn't where string end. 
    So we have to set new terminator after dest string have been generated
    */
    dest[100] = '\0';

    printf("Result: %s\n", dest);

    return 0;
}

/* 
Function will manipulate the value of the pointer so it doesnt return any thing. So we need 
1. We declare a bufer and the size of buffer. Buffer is an empty memory that have the size at least more than what need to store.
2. That Buffer is our destination. And before storing just what we need to that buffer, the original user input was store in arr.
3. Our job is to copy only just what we need from arr to dest, not fully.
Since we only need to move from pointer to pointer, we dont return anything, just manipulating function so need void function.
*/
void my_strncpy(char *A, char *B, int n){
    while(n-- > 0){ // while n - amount left to copy from begining decrement
        *A++ = *B++; // Give each index of A (A = dest) from A[0] an value from each elemnt of B (B = arr)
        // Both increment by 1 when tranfer take each B give to each A.
        // How many time ? take until n time count back and reach 0.
    }
}