/*
Practice 5.5.4 — my_strchr() (Character Search)
Find first occurrence of character in string
Return pointer to character, or NULL if not found
Example: strchr("hello", 'l') → pointer to first 'l'
*/
/*
PSEUDOCODE:
my_strchr(char *s, char c):
  1. Loop: while *s != '\0'
    - If *s == c (found):
      Return s (pointer to that character)
    - Move forward (s++)
  2. If end reached (not found):
    Return NULL

FLOWCHART:
my_strchr(s, c):
  |
  +-- WHILE (*s != '\0')
  |       |
  |       +-- IF *s == c
  |       |     Return s (pointer found)
  |       |
  |       +-- s++ (move forward)
  |       |
  |       +-- Check condition again
  |
  +-- Return NULL (character not found)

EXAMPLE:
  strchr("hello", 'l') → returns pointer to first 'l'
  strchr("hello", 'z') → returns NULL

COMPLEXITY:
  Time: O(n) — worst case: scan entire string
  Space: O(1) — no extra memory
*/
#include <stdio.h>

int main(){

    // User input the string
    char arr[100];
    char l;
    printf(" PLease input your string: ");
    scanf(" %[^\n]", arr);
    printf("And you looking for letter: ");
    scanf(" %c", l);

    //DISPLACE Result
    char *result = my_strchr(arr, l);

    /*
    To print the location of index that the found letter at , notice that
    arr = pointer to arr[0] (first element)
    result = pointer to arr[2] (where 'l' is found)
    so
    letter location's index = result - arr
    */
    if(result != NULL){
        printf("Letter %c first found in %dth index of the string.\n", result, result - arr);
    }else{
        printf("Not found!!!\n");
    }

    return 0;
}
/*
To find the first first time that an element ever exist in a string.
We need a function:
1. scan the entire string as an array not a pointer, so it can see each element
2. while scaning looking for the the letter first appearence and re turn it.
If not found letter at all the re turn 0 not found.
To find the second or third time the letter ever exist ,
We have to call the function again after it found the first occurence
using for loop or recursion but for loop is easier.
*/
// This function will return an address of single char so it the char poiter function
char *my_strchr(char *str, char s){
    while(*str != '\0'){ // while looping through string before reaching NULL
        if(*str++ == '\0'){ // mover pointer to the right untill NULL
            return str; // If reach NULL = not found Not found
        }
        str++;
        return NULL; // else if reach s before NULL, then we found it.
    }
}