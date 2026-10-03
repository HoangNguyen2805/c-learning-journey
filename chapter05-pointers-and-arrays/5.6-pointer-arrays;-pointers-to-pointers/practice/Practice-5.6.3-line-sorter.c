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
#include <stdlib.h>

#define MAXLEN   1000 // max length of one line
#define MAXLINES 5000 // max number of lines the array can hold

int readlines(char *lineptr[], int maxlines); // ACTION 1
void qsort_str(char *lineptr[], int left, int right); // ACTION 2
void writelines(char *lineptr[], int countline); // ACTION 3

void my_strcpy(char *destination, char *source);
int my_strlen(char *str);
void my_swap(char *v[], int i , int j);
int my_strcmp(char *A, char *B);

int main() {
    /*
    The program does 3 things:

    1. READ — Take lines typed in (or from a file)
    2. SORT — Put them in alphabetical order
    3. PRINT — Show the sorted lines
    */

    char *lineptr[MAXLINES]; // part of ACTION 1 - STEP 1

    // Step 1: READ lines
    // int countline = return nline from ACTION 1 , it store the amount of line ACTION 1 have readed.
    int countline = readlines(lineptr, MAXLINES);
    // and if readlines(return -1) fail, main will get a return -1 , if main receive -1 it should printout why it got it.
    if (countline == -1){
        printf("Error: Too many lines\n");
        return 1;
    }

    // Step 2: SORT lines
    // the left most is arr[0] and the right most is arr[countline - 1]
    /*
    Why countline - 1 ?
    Example:
    countline = 5 (5 lines read)
    Lines are at indices 0, 1, 2, 3, 4
    qsort_str(lineptr, 0, 5-1) = qsort_str(lineptr, 0, 4) ✓
    */
    qsort_str(lineptr, 0, countline - 1);

    // Step 3: PRINT lines
    writelines(lineptr, countline);

    // DON'T forget to free() memories of malloc.
    for(int i = 0; i < countline; i++){
        free(lineptr[i]);
    }
    
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

        /*between step 2 and step 3
        Step 2: clean up the line. Remove the \n so it's a proper string.
        Step 3: get memory for that one line.
        We have limited memory to store line, lineptr[MAXLINES] , so what if the amount of line is more than MAXLINES ?
        In that case we don't have enough storage to store in lineptr's slot , it should return and error, and it should return before generate more memory by malloc.
        */ 
        if (nlines >= maxlines){
            return -1;
        }
        // IF this readlines() function fail, it return -1 to masin, main need to do some thing with this -1 value other than nothing.

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
    // left is the beginning of the array
    // right is the ending of the array

    // Step 1
    // Base case - stop recurtion when there is no more eleemnt to compare
    if(left >= right){ // If the position where left is is eual or bigger than right mean both left and
        return;        //  right already at most right ( end of the array) so no more element to compare.
    }

    // Step 2
    // The pivot is the right most , poiter array element.
    char *pivot = lineptr[right];

    // Step 3
    // Where i should stand ?
    // - i should start at index before 0 because first round is checking we dont know i swap with what yet
    // i is integer, i is an index represent the position of element from left
    int i = left - 1;

    // Step 4
    // We use for loop because we know the exact range of the array. [left to right - 1] - why right -1 ? Because right is the pivot, we dont compare the pivot so right - 1 is the last element.
    // This is where we give meaning to j , j suppose to be at first element and we compare array[j] with array[pivot]. so j is increase as long as NOT reach Right ( j < right)
    for(int j = left; j < right; j++){
        /* 
        If arr[j] is SMALLER than arr[pivot]{
            // we swapping it to the left
            i++;
            call swap to swap i with j
        }
        No need if statement for BIGGER because j will keep j++
        */
        if(my_strcmp(lineptr[j], pivot) < 0){
            i++;
            my_swap(lineptr, i , j);
        }
    }

    // Step 5
    /* PLace pivot in final possition
    After the loop end compare complete, last step we need to place pivot in the middle where after all the small element but before all the big element
    j is at the most right after comparison, so i is at the most right of the smaller one
    so i + 1 is where pivot should be So:

    1. Swap lineptr[i+1] with lineptr[right]
    2. Set p = i + 1

    p is our new position of this current recursion
    */
    my_swap(lineptr, i + 1, right); // In step 2 we set char *pivot = lineptr[right];
    int p = i + 1;

    // After put the pivot in the correct position we need to call the function again (recursion) so it keep sorting the Bigger and Smaller element.
    // Step 6 - recursion left side (Smaller)
    // NEW left = p - 1
    qsort_str(lineptr, left, p-1);

    // Step 7 - recursion right side (Bigger)
    // NEW right = p + 1
    qsort_str(lineptr, p+1, right);
}

// Swap function
void my_swap(char *v[], int i , int j){
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* String compare function (strcmp)
```
my_strcmp(A, B):
    while A and B are equal and A is not null terminator:
        advance both pointers
    return A - B
```
When you do *A - *B, you're subtracting the ASCII values of the characters at that position.

Example:

'a' has ASCII 97
'b' has ASCII 98
'b' - 'a' = 1 (positive, so 'b' comes after 'a')

If both strings are identical, both hit \0 at the same time, so '\0' - '\0' = 0 (equal).

That's how you know which string comes first alphabetically.
*/
int my_strcmp(char *A, char *B){
    while(*A == *B && *A != '\0'){ // if A have different letter with B or B end before A or A end before B
        A++;
        B++;
    }
    return *A - *B;                // it should return the different between A and B
/*
If A is longer than B
A is ASDFGH
B is ASDFGHJKL
return 0 - JKL = negative

If A is shorter than B
A is ASDFGHJKL
B is ASDFGH
return JKL - 0 = positive

If A and B are the same
A is ASDFGH
B is ASDFGH
return 0 - 0 = 0
*/
}

/* ACTION 3 is to print the output in alphabetiacal order
after sorting , lineptr store all of the element in alphabetical order all we need is the for loop to print them out
*/
void writelines(char *lineptr[], int countline){
    for(int i = 0; i < countline; i++){
        printf("%s\n", lineptr[i]);
    }
}