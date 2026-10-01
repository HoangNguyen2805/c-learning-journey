/*
Write a program that reads lines from stdin, sorts them alphabetically, prints them.

Use three functions: readlines(), qsort_str(), writelines().

readlines() reads from stdin until EOF, malloc's storage for each line, stores addresses in an array, returns count.

qsort_str() quicksorts the pointer array alphabetically.

writelines() prints each line.

Free all malloc'd memory before exit.

Go.
*/

#include <stdio.h>

#define MAXLEN   1000 // max length of one line
#define MAXLINES 5000 // max number of lines the array can hold

int readlines(char *lineptr[], int maxlines);
void my_strcpy(char *destination, char *source);
int my_strlen(char *str);

int main() {

    char *lineptr[MAXLINES]; // part of ACTION 1 - STEP 1


    return 0;
}

/*  ACTION 1 is create function that read line and in the readline function we use while loop to read while not NULL yet , while loop have 4 step
readlines(lineptr, maxlines):
    Parameters:
        lineptr = array of pointers (declared in main as char *lineptr[MAXLINES])
        maxlines = max size of the array (to prevent overflow)
    
    Variables:
        nlines = counter, starts at 0
        line[MAXLEN] = temp buffer for fgets
    
    while (fgets reads from stdin and is not NULL):
        Step 1: measure line length with strlen
        Step 2: strip the newline (replace \n with \0)
        Step 3: malloc storage for (length + 1) bytes
        Step 4: strcpy into storage, store address in lineptr[nlines++]
    
    return nlines
*/
int readlines(char *lineptr[], int maxlines){
    
    char line[MAXLEN]; // max length of one line is 1000
    int nlines = 0; // counter how many line you have store

    while(fgets(line, MAXLEN , stdin) != NULL){
        // Step 1
        int len = my_strlen(line);

        // Step 2
        // Ex: "banana\n\0" , so \n come before \0, move aray one character backward
        if (line[len - 1] == '\n'){
            line[len - 1] = '\0';
        }

        // Step 3
         char *storage = malloc(len + 1);

         //part of malloc 
         if (storage == NULL){
            return -1;
         }

        // Step 4
        my_strcpy(storage, line); // copy the string
        lineptr[nlines++] = storage; // each time you store a string nlines increase as lineptr array chagne to next slot for next string.

    }

    return nlines;
}

/*
my_strlen(str):

Declare a counter, start at 0

Loop while the character is not the null terminator:
Increment the counter
Move to the next character

Return the counter

int my_strlen(char *str):
    Declare a counter, start at 0
    
    Loop while the character at str is not null terminator:
        Increment the counter
        Move str to the next character
    
    Return the counter
*/
int my_strlen(char *str){
    int counter = 0;
    while(*str != '\0'){
        str++;
        counter++;
    }
    return counter;
}

/* Pseudocode for strcpy:
my_strcpy(destination, source):
    Loop while source character is not null terminator:
        Copy source character to destination
        Move both pointers forward
    Copy the null terminator
*/
void my_strcpy(char *destination, char *source){
    while (*source != '\0'){
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
}

/* ACTION 2 is to sort them line in alphabetical order using qsort_str() — the quicksort function.
qsort_str(lineptr, left, right):
    
    STEP 1: Base case — when to stop recursing
        if left >= right:
            return
        Why? If left >= right, there's 0 or 1 elements left. Already sorted.
              No need to do anything. Stop this recursive call.
    
    STEP 2: Pick the pivot — the dividing point
        pivot = lineptr[right]
        Why? Choose the rightmost element as our dividing reference.
              We'll organize everything relative to this pivot.
    
    STEP 3: Initialize the smaller boundary tracker
        i = left - 1
        Why? `i` marks where the smaller section ends.
              Start at -1 (before the range) because nothing is smaller yet.
    
    STEP 4: Partition — organize smaller left, larger right
        for j from left to right-1:
            if lineptr[j] < pivot (alphabetically, use my_strcmp):
                i++                              // expand smaller section 
                swap lineptr[i] with lineptr[j] // put smaller element there 
        Why? Scan every element except pivot. If smaller than pivot, move it left.
             After loop, all smaller are left of i, all larger are right of i.
    
    STEP 5: Place pivot in final position
        swap lineptr[i+1] with lineptr[right]
        p = i + 1
        Why? Pivot belongs between smaller (left) and larger (right).
             Position p is now pivot's final, correct location.
    
    STEP 6: Recursively sort the LEFT side
        qsort_str(lineptr, left, p-1)
        Why? Left side [left to p-1] still unsorted. Call qsort_str on it.
             The function will partition THAT range, then recurse on its sides.
             (This is recursion — function calling itself)
    
    STEP 7: Recursively sort the RIGHT side
        qsort_str(lineptr, p+1, right)
        Why? Right side [p+1 to right] still unsorted. Call qsort_str on it.
             Same process: partition, then recurse on its sides.
*/
void qsort_str(char *lineptr[], int left, int right){
    if(left >= right){ // left and right is indices integers 
        return; // we sort from left to right , if left is at the position that = to right mean they at the end, so nothing to sort any more
    }

    char *pivot = lineptr[right];
    int i = left - 1;
    int j = right;

}