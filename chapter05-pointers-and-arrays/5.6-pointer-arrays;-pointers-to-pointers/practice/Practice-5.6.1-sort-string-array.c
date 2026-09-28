/*
Practice 5.6.1 — Selection Sort on Pointer Array
Sort an array of string pointers in alphabetical order.

Problem:
You have an array of pointers to strings:
    char *words[] = {"banana", "apple", "cherry", "date", "fig"};

Write a function that sorts them alphabetically using selection sort.

Constraints:
- Use your my_strcmp() from 5.5 to compare strings
- Write a swap() helper that exchanges pointers (not strings)
- No standard library sort — implement it yourself
- Test with at least 5 words

Hint:
Selection sort: find the smallest, swap it to position i, repeat.
When comparing pointers, you need strcmp — 
v[i] < v[j] won't work. You need my_strcmp(v[i], v[j]) < 0.

Complexity: O(n²) time, O(1) space
*/
/* 
#include <stdio.h>

int my_strcmp(char *A, char *B) {
     your code from 5.5 
}

void swap(char *v[], int i, int j) {
     your code 
}

void sort(char *v[], int n) {
     your code 
}

int main() {
    char *words[] = {"banana", "apple", "cherry", "date", "fig"};
    int n = 5;
    
     call sort 
    
     print the sorted array 
    
    return 0;
}

PSEUDOCODE:

sort(array, count):
    for each position i from 0 to count-1:
        smallest = i
        for each position j from i+1 to count-1:
            if string at j comes before string at smallest:
                smallest = j
        swap position i and position smallest

BEST APPROACH:

Selection sort. Why? Simple, works on arrays, you only swap pointers (not strings).

COMPLEXITY:

Time: O(n²) — two nested loops, every element compared to every other
Space: O(1) — no extra memory (just a temp variable in swap)

This is the classic choice for sorting a small pointer array.

Now write the code.
*/

//code here
#include <stdio.h>

int my_strcmp(char *A, char *B);

void swap(char *v[], int i, int j);

void sort(char *v[], int n);

int main() {
    char *words[] = {"banana", "apple", "cherry", "date", "fig"};
    int n = 5;
    
    /* call sort */
    
    /* print the sorted array */
    
    return 0;
}

void swap(char *v[], int i, int j) {
    /* your code */
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*
my_strcmp - string compare
loop until \0, if
both end up at \0 - same string - return 0

if- they diferent at some point - return *First - *Second
  - first come BEFORE second - return negative
  - first come AFTER second - return possitive
but we only need to return *First - *Second once because it work with the other 2 condition
If A's character comes earlier alphabetically, it's a smaller ASCII value, so the difference is negative. If A comes later, the difference is positive.
A is holding the address of an aray, so A = A[banana] for example.
*/
int my_strcmp(char *A, char *B) {
    /* your code from 5.5 */
  while(*A == *B && *A != '\0'){
    A++;
    B++;
  }
  return *A - *B;
}

void sort(char *v[], int n) {
    /* your code */
}