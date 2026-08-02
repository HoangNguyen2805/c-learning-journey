/*
Practice 5.6.2 — Sort by a Different Criterion

Same array as 5.6.1, but sort by string length, shortest first. Ties broken
alphabetically.

              Practice 5.6.1 — Sort an Array of Strings

              Sort the array below into alphabetic order and print the result. Sort by
              rearranging the pointer array. Do not copy any string.

              Use selection sort — not quicksort. The point here is the pointer handling,
              not the algorithm.

Then produce both orderings in one run — length order, then alphabetical —
without writing the sort twice.

Constraints:
- One sort function, called twice
- No copying of string data
- Ties in length resolved with strcmp

Hint, not a solution:
  A sorting algorithm does not care what "comes before" means. It only asks a
  question and acts on the answer. If that question is hard-coded inside the
  sort, you need two sorts. If it is not, you need one.

  The straightforward move at this stage is an extra parameter — a flag the
  sort consults when comparing. Do that first. It works and it is honest code.

  Then, if you want to reach ahead: K&R develops the better answer in 5.11 by
  passing the comparison function itself. The parameter you would need is

      int (*comp)(char *, char *)

  Write it the flag way, then the function-pointer way, and notice which one
  you would rather extend to a third ordering.

DSA concept: separating ordering policy from sorting mechanism
Approach: parameterized comparison
Time: O(n^2) with selection sort, unchanged by which comparison is used
Space: O(1)

Expected length order (ties alphabetical):
  fig date apple grape banana cherry elderberry

Follow-up: add a third ordering — by last character. How many lines of your
program have to change? That number is the answer to whether you factored the
comparison out properly.
*/
/*Given:
#include <stdio.h>
#include <string.h>

void swap(char *v[], int i, int j);

int main()
{
    char *words[7];

    words[0] = "banana";
    words[1] = "apple";
    words[2] = "cherry";
    words[3] = "date";
    words[4] = "elderberry";
    words[5] = "fig";
    words[6] = "grape";

    return 0;
}
*/

// Structure 1 — two separate sorts (what you just proposed) Not very efficient for complexity.


#include <stdio.h>
#include <string.h>

void sort_length(char *v[], int n);
int my_strlen(char *arr);
void sort_alpha(char *v[], int n);
int my_strcmp(char *A, char *B);
void swap(char *v[], int i, int j);

int main()
{
    char *words[7];

    words[0] = "banana";
    words[1] = "apple";
    words[2] = "cherry";
    words[3] = "date";
    words[4] = "elderberry";
    words[5] = "fig";
    words[6] = "grape";

    printf("Given:\n"
           "char *words[7];\n\n"

           "words[0] = \"banana\";\n"
           "words[1] = \"apple\";\n"
           "words[2] = \"cherry\";\n"
           "words[3] = \"date\";\n"
           "words[4] = \"elderberry\";\n"
           "words[5] = \"fig\";\n"
           "words[6] = \"grape\";\n");
    
    printf("\nSorting...\n\n");

    sort_length(words, 7);
    for(int i = 0; i < 7; i++){
        printf("%s\n", words[i]);
    }

    printf("\n");

    sort_alpha(words, 7);
    for(int j = 0; j < 7; j++){
        printf("%s\n", words[j]);
    }

    return 0;
}
/* 
`sort_length` To sort the length of the string, short first, long later, we need 
- A function sorting the string length , reoder by the length of the string

`strlen()` To help with sorting the length of the string, we need strlen from <string.h> , or we can make it our own my_strlen
- A function to count how many element is in the array.

`sort_alpha` If string length is equal to each other then, sort those string by order of alphabet,
a have value of number that is smaller than z, a is smallest in value and the value go up a long the alphabet. So we need
- A function sorting by comparing character by character, reorder by the value of the character.

`strcmp()` If both string have the same length now we have to look into the fact that is the order need to be in alphabetical order,
so we need to compare the character to see if each character is smaller or bigger by it number value. Each letter have number value from
small to big parrallel with alphabet from berginning to the end of alphabet.
- strcmp compare the character by it number value.

`swap()` Both function need take two pointer and move it left right by the result,
To move pointer we need
- A swap function to swap place of the pointer base on result of the other 2 function.

Basically string length function and alphabet function will call swap when it done sorting. swap call within the 2 function.

main ─┬─> sort_alpha ─┬─> my_strcmp     (inner loop, every comparison)
      │               └─> swap          (outer loop, once per pass)
      │
      └─> sort_length ┬─> my_strlen     (inner loop, twice per comparison)
                      ├─> my_strcmp     (inner loop, ties only)
                      └─> swap          (outer loop, once per pass)

*/

// sort_length — selection sort, shortest string first.
// Ties in length are broken alphabetically.
//
// Same structure as sort_alpha. The only difference is the comparison:
// instead of one my_strcmp call, it measures both strings and subtracts,
// falling through to my_strcmp only when the lengths match.
void sort_length(char *v[], int n){
    for(int i = 0; i < n; i++){
        int smallest = i;                  // guess: assume slot i already holds the winner
        for(int j = i + 1; j < n; j++){

            // Length difference. v[j] shorter -> negative -> v[j] wins.
            // Same argument order as my_strcmp: candidate first, guess second.
            int diff = my_strlen(v[j]) - my_strlen(v[smallest]);

            // diff == 0 means equal length. That would fire nothing below,
            // so overwrite diff with the alphabetical answer instead.
            if(diff == 0)
                diff = my_strcmp(v[j], v[smallest]);

            // Negative from either test means v[j] beat the guess.
            if(diff < 0)
                smallest = j;              // record its position
        }
        swap(v, smallest, i);              // move the winner into slot i
    }
}

int my_strlen(char *arr){ // counting character in string. string end with `\0n`
    int count = 0;
    while(*arr != '\0'){ // while string is not reach the end \0
        count++;         // every while count each character
        *arr++;          // every while loop index move 1 character from left to right
    }
    return count;        // return count
}

// sort_alpha — selection sort, alphabetical order. Length is irrelevant.
//
// Nested loops:
// Outer: walks i across positions. Sets smallest = i as a guess, then after
//        the inner loop finishes, swaps the winner into slot i.
// Inner: starts at i+1, compares each remaining string against the current
//        guess. Records the winning position in smallest. Nothing moves
//        during the scan.
void sort_alpha(char *v[], int n){
    for(int i = 0; i < n; i++){        // n = number of elements; valid slots are 0..n-1
        int smallest = i;              // guess: assume slot i already holds the winner
        for(int j = i + 1; j < n; j++){
            if(my_strcmp(v[j], v[smallest]) < 0){
                smallest = j;          // v[j] beat the guess — record its position.
                                       // The loop keeps going; later comparisons now
                                       // test against v[smallest], this new best.
            }
        }
        swap(v, smallest, i);          // move the winner into slot i
    }
}

int my_strcmp(char *A, char *B){ // comparing each character of both equal length size 
    while (*A == *B){
        if(*A == '\0'){ // If character of both are alike then *A - *B = 0
            return 0;
        }
        A++;  // while looping through character of string A and string B
        B++;  // Move both A and B index to the right 1 per loop to compare every single character.
    } // Inside while loop is what if they are the same character same number value.
//  out side loop is if there is different the character closer to begining of alphabet is smaller no to go to top
return *A - *B;
/*
If *A - *B = negative --> A is smaller than B
If *A - *B = 0 --> return 0
If *A - *B = positive --> A is bigger
NO *B - *A EVER
*/
}

void swap(char *v[], int i, int j){ // v is an array of pointers; each slot holds the address of a string
    // swap exchanges the values of slot i to slot j
    char *temp = v[i];   /* copy slot i's value into temp */
    v[i] = v[j];         /* copy slot j's value into slot i */
    v[j] = temp;         /* copy temp's value into slot j */
    /* Given arr[i] = "apple" and arr[j] = "banana". Called swap(v[], i, j);
        1. swap set temp = "apple".
        2. swap set arr[i] = "banana".
        3. swap set arr[j] = temp (which set arr[j] = "apple").
    */
}












// Structure 2 — one sort, flag parameter (Option A)

/*
Option A — inline, right there in the `if`. An `if/else` inside the inner loop 
picking which comparison to run.
```c
void sort(char *v[], int n, int mode);
void swap(char *v[], int i, int j);

main:
    sort(words, 7, 0);   // 0 = alpha 
    print
    sort(words, 7, 1);   // 1 = length 
    print
```
One function. The loops exist once. Inside, mode picks the comparison.
*/

/*
#include <stdio.h>
#include <string.h>

void swap(char *v[], int i, int j);

int main()
{
    char *words[7];

    words[0] = "banana";
    words[1] = "apple";
    words[2] = "cherry";
    words[3] = "date";
    words[4] = "elderberry";
    words[5] = "fig";
    words[6] = "grape";

    return 0;
}
*/




















// Structure 3 — one sort, comparison function (Option B)

/*
Option B — a separate function `int compare(char *a, char *b, int mode)` 
that the sort calls, so the sort body reads `if (compare(words[j], words[smallest], mode) < 0)`.
```c
void sort(char *v[], int n, int mode);
int  compare(char *a, char *b, int mode);
void swap(char *v[], int i, int j);
```
Same as 2, but the comparison moves into its own function. 
The sort stops knowing anything about strings.
*/
/*
#include <stdio.h>
#include <string.h>

void swap(char *v[], int i, int j);

int main()
{
    char *words[7];

    words[0] = "banana";
    words[1] = "apple";
    words[2] = "cherry";
    words[3] = "date";
    words[4] = "elderberry";
    words[5] = "fig";
    words[6] = "grape";

    return 0;
}
*/