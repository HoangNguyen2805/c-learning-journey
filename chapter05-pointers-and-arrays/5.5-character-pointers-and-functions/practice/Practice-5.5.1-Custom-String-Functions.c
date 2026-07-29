/*
Practice 5.5.1 — Custom String Functions
Implement strlen, strcpy, and strcmp from scratch using pointer arithmetic (no built-in string functions). Test them with user input strings.
*/
/*
CUSTOM STRING FUNCTIONS (Using Pointer Arithmetic)

Why implement these?
- Understand how standard library functions work (strlen, strcpy, strcmp)
- Master pointer arithmetic with strings
- Learn null terminator navigation
- No built-in functions allowed!

FUNCTION 1: strlen(char *s)
- Count characters in string
- Loop until you hit '\0'
- Return the count

FUNCTION 2: strcpy(char *dest, char *src)
- Copy each character from src to dest
- Stop when you hit '\0' in src
- Important: Copy the '\0' too!

FUNCTION 3: strcmp(char *s1, char *s2)
- Compare two strings character by character
- Return 0 if equal
- Return negative if s1 < s2
- Return positive if s1 > s2

KEY INSIGHT:
All use pointer arithmetic to walk through strings until '\0'
No array indexing needed!
*/
/*
Inoder to use this function 
- strlen()
- strcpy()
- strcmp()
We have to declare the new header file which is 
    #include <stdlib>
But in this exercise assume that we NOT using `#include <stdlib>`, and 
our job is to write a function that do same job as 3 function above.

Notice that the function is to manipulate string in form of array not pointer.
    String in form of array:
    ```c This is possible to manipulate
    char amessage[] = "now is the time";  // array of chars
    ```

    String in form of pointer;
    ```c This is NOT possible to manipulate
    char amessage[] = "now is the time";  // array of chars
    ```
*/
/*PSEUDOCODE
strlen(char *s):
  1. Create counter = 0
  2. Loop: while *s != '\0'
    - Increment counter
    - Move s forward (s++)
  3. Return counter

strcpy(char *dest, char *src):
  1. Loop: while *src != '\0'
    - *dest = *src (copy character)
    - Move both forward (src++, dest++)
  2. *dest = '\0' (copy null terminator)
  3. Return dest

strcmp(char *s1, char *s2):
  1. Loop: while *s1 != '\0' AND *s2 != '\0'
    - If *s1 != *s2:
      Return (*s1 - *s2) (positive or negative)
    - Move both forward (s1++, s2++)
  2. If loop ends equal:
    Return 0
*/
/*FLOWCHART
strlen(s):
  count = 0
  |
  +-- WHILE (*s != '\0')
  |       |
  |       +-- count++
  |       |
  |       +-- s++
  |       |
  |       +-- Check condition again
  |
  +-- Return count

strcpy(dest, src):
  |
  +-- WHILE (*src != '\0')
  |       |
  |       +-- *dest = *src
  |       |
  |       +-- src++, dest++
  |       |
  |       +-- Check condition again
  |
  +-- *dest = '\0'  (Copy terminator!)
  |
  +-- Return dest

strcmp(s1, s2):
  |
  +-- WHILE (*s1 != '\0' AND *s2 != '\0')
  |       |
  |       +-- IF *s1 != *s2
  |       |     Return (*s1 - *s2)
  |       |
  |       +-- s1++, s2++
  |       |
  |       +-- Check condition again
  |
  +-- IF we exited loop:
  |     Return 0 (strings are equal)
*/
#include <stdio.h>

int my_strlen(char *arr);
void my_strcpy(char *A, char *B);
int my_strcmp(char *A, char *B);

int main(){

    // Now let use Do while loop to give use an option to chose wwhich function they want to use.
    int choice;
    do {
        // DISPLAY MENU
        printf("\n\n=== String Functions Menu ===\n\n");
        printf("1. Test strlen - String Length\n");
        printf("2. Test strcpy -  String Copy\n");
        printf("3. Test strcmp - String Compare\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf(" %d", &choice);

        char arr[100];
        char clonearr[100];
        char arrA[100];
        char arrB[100];
        
        // PROCESS CHOICE
        switch(choice){
            case 1:
              printf("Enter your string: ");
              scanf(" %[^\n]", arr);
              printf("The length of your string is %d character long, including white space.", my_strlen(arr));
              break;

            case 2:             // should we use malloc
              printf("Enter your string: arr = ");
              scanf(" %[^\n]", arr);
              my_strcpy(clonearr, arr);
              printf("Copy arr to clonearr, clone arr = %s\n", clonearr);
              break;
              
            case 3:
              printf("Enter your first string: ");
              scanf(" %[^\n]", arrA);
              printf("Enter your second string: ");
              scanf(" %[^\n]", arrB);
              
              printf("\nComparing 2 Strings ...\n");
              int result = my_strcmp(arrA, arrB);

              /*
              strcmp() DOESNT comapre string length 
              - It convert both character into number then compare each character by it number value.
              The value go up From the begging of the alphabet to the end of alphabet.
              Ex:
              a is the smallest when conver to number
              z is the biigest when converting to number.

              So sometime we might see:
                          "xwqxqxqedq" vs "qxqwqqxqcqecqeceqc"

                          First chars: 'x' vs 'q'ç
                        120 vs 113
                        120 > 113 → First string is BIGGER ✓
              */
              if(result == 0){
                printf("First string and Second string are EQUAL!!!\n");
              } else if(result > 0){ // result = positive , A is BIGGER
                printf("First string are BIGGER than Second string.\n");
              } else {               // result = negative , A is SMALLER
                printf("First string are SMALLER than Second string.\n");
              }
              break;

            case 4:
              printf("Existing...\n");
              break;

            default:
            printf("Invalid choice, try again!!!\n");
        }

    } while (choice != 4);

    
    return 0;
}

// Function 1 - strlen() - Strlen Length - How many letter is in the string?
// the function is to counting letter but we'll return integer , so it int function.
int my_strlen(char *arr){
    // to count and looping amount base on entry (input)
    // In c , all string end with \0 so , we'll looping in array until we reach \0
    int count = 0;
    while(*arr != '\0'){
        // we'll count first and move to the left of the array after count.
        // if move first before count, we'll miss count index 0. 

        // while we have reach \0 yet, each element the compiler go though
        // we will increase variable count by one. So we have to set that variable to 0 first,
        // and since we don't want that count variable reset each loop we declare it above the loop.
        count ++;

        // now we move left one unit on the array after counting it.
        arr++; 
        // arr by default will = arr[0] to move from arr[0] to arr[1] we'll use increment ++ , to move right
        // to move arr[0] to arr[-1] we'll decrement -- to the left
    } // when it reach \0 loop stop here and the function should return the value of count.
    return count;
}

// Function 2 - strcpy() - String Copy - How to copy letter from an array to another array.
// the function will move letter from this array to another, we don't return anything, just 
// moving pointer to pointer so we will use void fuinction
void my_strcpy(char *A, char *B){
    // to coppy every element from arr to clonearr, we need to point at every element 
    // using while loop, while arr not reach \0.
    // point at address of arr (derefence arr)
    // set the address of arr to adress of clonearr , thats all
    // each while loop arr move right 1 by increment, clone arr also have to move the same because we're coping.
    // loop until arr reach \0, we also copy \0 from arr to clonearr
    while((*A++ = *B++)){ // In this case B = user input
        ;
    } // when clonearr reach \0 , loop stop, but why ?
    // condition is while arr = clonearr, each elemnt consider TRUE to keep the loop going.
    // BUT in c \0 = NULL terminator, and NULL mean FALSE which the condition to stop the loop.
}

// Function 3 - strcmp() — String Compare - How do we know arr A is equal or bigger or less than arr B ?
// Notice that in c 
//                0 = FALSE
// BUt     non-zero = TRUE   , In this case true/false doesnt matter.
// Return value mean end of { } and return what it want to return.

/* THIS IS STANDARD
strcmp(s1, s2) returns:
  0  → equal
  <0 → s1 is smaller
  >0 → s1 is bigger
*/

// NOTICE: `return` = END OF { } block , REGARLESS OF WHAT VALUE IS BEING RETURN.

/*
So , Equal will, return 0
     Bigger will return how big A is more than B, return A - B
     Smaller will return how small A is more than B, return A - B
Notice that A is ALWAY - Subtract B
Never B - A
*/
// Either way the function will return the number so it's integer.
int my_strcmp(char *A, char *B){
    // while comparring A == B
    while(*A == *B){
        // If equal then A - B = 0, so the loop help read A
        // and find out that all element of A same as B till 
        // the end of A which is \0, so if equal till the end , return 0
        if(*A == '\0'){
            // mean while increment to the right index on both
            A++;
            B++;
        }
        return 0; // return 0 the same
        // While check A == B , i some element is different
        // return the different in from of A - B
      }
      return *A - *B; // return the different , IF A - B = Positive number, -> A is BIGGER
                    //                        IF A - B = Negative number, -> A is SMALLER
} // The if stament will increment  the location to the right
  // As long as A == B still, 
  // if see the diffrent if statement will end and return the different