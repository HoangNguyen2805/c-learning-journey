/*
[FROM K&R] Exercise 5-7

Book text:
  "Rewrite readlines to store lines in an array supplied by main, rather than
  calling alloc to maintain storage. How much faster is the program?"

Start from your 5.6.3. Instead of one malloc per line, main declares a single
large char array and readlines packs the lines into it end to end.

    char storage[MAXSTORAGE];

Each line goes in immediately after the previous one, and lineptr[i] points at
where that line begins inside storage.

    storage:  f i r s t \0 s e c o n d \0 t h i r d \0 . . .
              ^           ^             ^
              lineptr[0]  lineptr[1]    lineptr[2]

Constraints:
- Exactly one large buffer, declared in main, passed to readlines
- readlines must not overrun it
- No malloc at all

Hint, not a solution:
  You need to track where the next free byte is. That is a pointer that moves
  forward by the length of each stored line, plus one for the terminator.

  Two things can now go wrong that could not before: too many lines, and too
  many total characters. They are different limits, hit under different inputs,
  and both need checking. A file of 10 huge lines and a file of 10000 tiny ones
  fail in different ways.

Answer the book's actual question — do not guess:

  Generate a large input first:
      seq 1 200000 | shuf > big.txt

  Then time both versions on the same file:
      time ./sorter_malloc < big.txt > /dev/null
      time ./sorter_array  < big.txt > /dev/null

  Record the numbers in a comment at the bottom of this file. Say whether the
  difference matched what you expected, and where the time is actually going.
  If the two are closer than you predicted, that itself is the finding — most
  of the work in this program is not allocation.

Then answer the question K&R does not ask: what did you give up?
  The malloc version handles one enormous line and a million tiny ones equally
  well. This one does not. Describe the input that breaks the array version but
  not the malloc version.

DSA concept: arena allocation — one bulk reservation carved into pieces
Approach: bump a pointer through a fixed buffer
Time: per-line allocation drops from a malloc call to a pointer addition
Space: O(MAXSTORAGE) fixed, used or not

TIMING RESULTS (fill this in):

  malloc version:
  array version:
  observation:
*/
/*Given:
#include <stdio.h>
#include <string.h>

#define MAXLINES   5000
#define MAXLEN     1000
#define MAXSTORAGE 100000

int main()
{

    return 0;
}
*/


#include <stdio.h>

#define MAXLINES   5000
#define MAXLEN     1000
#define MAXSTORAGE 100000

// ACTION 1 - Read
int readlines(char *lineptr[] , int maxlines , char storage[] , int maxstorage);
int my_strlen(char str[]);
void my_strcpy(char destination[] , char source[]);

// ACTION 2 - Sort
void qsort_str(char *v[], int left, int right);
int my_strcmp(char *A, char *B);
void my_swap(char *v[] , int i , int j);

// ACTION 3 - Write
void writelines(char *lineptr[], int nlines);

int main(){

    // ACTION 1 - Read
    char *lineptr[MAXLINES];
    char storage[MAXSTORAGE];
    int nlines = readlines(lineptr , MAXLINES , storage , MAXSTORAGE);

    if(nlines == -1){
        printf("There is not enough slot.\n");
        return -1;
    } else if(nlines == -2){
        printf("There is not enough storage.\n");
        return -2;
    }

    // ACTION 2 - Sort
    qsort_str(lineptr, 0 , nlines - 1);

    // ACTION 3 - Write
    writelines(lineptr, nlines);

  return 0;
}

/* ACTION 1 — readlines: read lines into one big buffer (no malloc)

readlines(lineptr, maxlines, storage, maxstorage):

    Parameters:
        lineptr    = array of pointers (slots), declared in main
        maxlines   = how many slots lineptr has
        storage    = the one big char buffer, declared in main
        maxstorage = how many bytes storage has

    Variables:
        line[MAXLEN] = scratch space, each line lands here first
        countlines       = lines stored so far, starts at 0
                       (also the index of the next empty slot)
        p            = next free spot in storage, starts at the beginning of storage

    while (fgets reads a line into line, and does not return NULL):

        Step 1: measure the line
                len = my_strlen(line)

        Step 2: remove the \n
                if the last character, line[len - 1], is \n:
                    replace it with \0
                    make len one smaller   (so len is always the real length)
                if there is no \n (often the last line of a file): do nothing

        Step 3: CHECK 1 — is there a free slot in lineptr?
                if countlines >= maxlines:
                    return -1   (too many lines)

        Step 4: CHECK 2 — is there room left in storage?
                bytes needed = len + 1          (letters + \0)
                bytes used   = p - storage
                bytes left   = maxstorage - bytes used
                if bytes needed > bytes left:
                    return -2   (not enough storage)

        Step 5: copy the line from line into storage, starting at p

        Step 6: record where the line starts
                lineptr[countlines] = p
                countlines++

        Step 7: move p forward past the line and its \0
                p = p + len + 1

    return countlines
*/
int readlines(char *lineptr[] , int maxlines , char storage[] , int maxstorage){ // readline is an integer function because it return the number of line it read. [ 3 = 3 line ] , [ -1 = too many line ] , [ -2 = not enough storage ]
    /*parameter , readlines needs four, in this order:
    readlines needs four, in this order:
        1. the slots array: type? name?
        2. how many slots: type? name?
        3. the big char buffer: type? name?
        4. its size: type? name?
    */
    // We'll use fgets() to collecting the character while it not reach '\0' , notice that fgets() put '\n' infront of '\0'
    // fgets( where to put the line , how much room there , where to read from)
    /*
    Local variables (declare these before the while loop):

    line   = scratch space
             a char array that holds one line
             size: MAXLEN
             fgets puts each line here first

    countlines = line counter
             an integer
             starts at 0, because no lines are stored yet
             also the index of the next empty slot in lineptr

    p      = next free spot in storage
             a pointer to a char
             starts at the beginning of storage,
             because nothing has been stored yet
    */
    char line[MAXLEN];
    int countlines = 0;
    char *p = storage;
    while(fgets(line , MAXLEN , stdin) != NULL){
        // Step 1: measure the line
        int len = my_strlen(line);

        // Step 2: remove the \n
        // notice that fgets() put '\n' infront of '\0'. Ex: [ h , e , l , l , o , \n , \0 ] , we need to remove \n by replace \n with \0.
        if(line[len - 1] == '\n'){
            line[len - 1] = '\0';
            len = len - 1;
        }

        // Step 3: CHECK 1 — is there a free slot in lineptr? CHECK FOR lineptr
        // check to see if lineptr still have some SLOT to store the string, if countlines is bigger than or Equal to MAXSTORAGE then return -1 , make sure when main receive -1, do something with that -1
        if(countlines >= maxlines){
            // why bigger AND EQUAL TO ? Because slot is number from 0, so if we have maxlines = 3 mean slot[0] , slot[1] , slot[2] 
            //                                        and countline is 0	lineptr[0]  Exist
            //                                                         1	lineptr[1]  Exist
            //                                                         2	lineptr[2]  Exist
            //                                                         3	lineptr[3]  Not Exist , why > ? countlines never actually goes past maxlines so == would work
            return -1;
        }

        // Step 4: CHECK 2 — is there room left in storage? CHECK FOR MAXSTORAGE
        // check to see if MAXSTORAGE still have some SPACE to store the string, does this line fit in storage ?
        // RULE: if the bytes needed are bigger than the bytes left , it doesn't fit , so return -2.
        // len + 1                    = the size of the string 
        // p                          = next free spot in storage
        // p - storage                = bytes already used
        // maxstorage - (p - storage) = bytes left
        // so if len + 1 is biggert than maxstorage - (p - storage), return -2, when main receive -2, make sure main do somehting with -2
        if((len + 1) > (maxstorage - (p - storage))){
            return -2;
        }

        // Step 5: copy the line from line into storage, starting at p
        // After measure the line and remove \n and check and verified that the line is fit in the storage, now we copy the line into storage using my_strcpy
        my_strcpy(p , line); // p id the next free spot in storage

        // Step 6: record where the line starts
        // We havent give a meaning of next free spot on storage to p yet, now is the time
        lineptr[countlines] = p; // Put p into the next empty slot of lineptr
        countlines++; // Count one more line, so the next line goes into the next slot.

        // Step 7: move p forward past the line and its \0
        // After "banana" (len 6), p is at index 0 and has to end up at index 7, the first free spot after banana\0.
        // To store the second string , we have to place it next to the \0 of the first string now mpoiter is point at \0 we need to move it over one unit. len is where the pointer at.
        p = p + len + 1; // p is 0 + len of banana is + 7 and plus 1 = after \0 of banana\0 and that is where we store next string.
    }

    // return
        return countlines;
}

/*
my_strlen(str):
    receives: str, a pointer to the start of a string
    returns:  the number of characters (an int), not counting \0

    declare a counter, start at 0

    loop while the character at str is not the null terminator \0:
        add 1 to the counter
        move str to the next character

    return the counter
*/
int my_strlen(char str[]){
    int count = 0;
    while(*str != '\0'){
        str ++;
        count ++;
    }
    return count;
}

/*
my_strcpy(destination, source):
    receives: destination, a pointer to where the copy goes
              source, a pointer to the string to copy
    returns:  nothing (void)

    loop while the character at source is not the null terminator \0:
        copy the character at source into the spot at destination
        move source to the next character
        move destination to the next spot

    the loop stopped at \0 without copying it, so:
        put \0 at the spot destination now points to
*/
void my_strcpy(char destination[] , char source[]){
    while(*source != '\0'){
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; // copy stop at \0 so new destination doesnt have \0 yet, we have to add them
}

// ACTION 2 - qsort_str: sorting and storing line in an alphabetical order.
/*
Definition of QUICKSORT: 7 STEPS, traced on  5 2 8 1 4  (left = 0, right = 4)

index:      0  1  2  3  4
start:      5  2  8  1  4

STEP 1: Stop?
    Stop if left >= right (0 or 1 numbers).
    0 >= 4? No, keep going.

STEP 2: Pick the pivot
    pivot = the last one, v[4] = 4

STEP 3: Set i
    i = left - 1 = -1
    (i = end of the "smaller" section, which is empty for now)

STEP 4: j scans from left to right - 1, moving smaller ones left
    j=0:  5 < 4? no  → skip                      5  2  8  1  4
    j=1:  2 < 4? yes → i=0, swap v[0],v[1]       2  5  8  1  4
    j=2:  8 < 4? no  → skip                      2  5  8  1  4
    j=3:  1 < 4? yes → i=1, swap v[1],v[3]       2  1  8  5  4

STEP 5: Put the pivot after the smaller ones
    swap v[i+1], v[right] → swap v[2], v[4]      2  1  4  5  8
    p = i + 1 = 2
    4 is in its final place.

STEP 6: Sort the left side, left to p-1  → index 0 to 1:  [2 1]
STEP 7: Sort the right side, p+1 to right → index 3 to 4: [5 8]
    (each side repeats steps 1 to 7)

Result:     1  2  4  5  8

For lines: "a < b" means my_strcmp(a, b) < 0
*/
/*
qsort_str(v, left, right):
    receives: v, the array of pointers (lineptr)
              left, the first index of the range to sort
              right, the last index of the range to sort
    returns:  nothing (void), it rearranges v directly

    Step 1: Base case — when to stop
        if left >= right:
            return
        (0 or 1 lines in the range, already sorted)

    Step 2: Pick the pivot
        pivot = the address in v[right]
        (the last line in the range; pivot is a pointer to char)

    Step 3: Start the boundary tracker
        i = left - 1
        (i marks the END of the "smaller than pivot" section.
         It starts just before the range, because nothing is in that section yet.)

    Step 4: Partition — move smaller lines to the left
        for j from left up to right - 1:
            if my_strcmp(v[j], pivot) < 0:      (v[j] comes before the pivot)
                i++                              (make room in the smaller section)
                swap v[i] and v[j]               (put v[j] into that room)
        (skip right itself, because that's the pivot)

    Step 5: Put the pivot in its final place
        swap v[i + 1] and v[right]
        p = i + 1
        (everything left of p is smaller, everything right of p is bigger)

    Step 6: Sort the left part
        qsort_str(v, left, p - 1)

    Step 7: Sort the right part
        qsort_str(v, p + 1, right)
*/
void qsort_str(char *v[], int left, int right){
    // Step 1: Base case — when to stop
    if(left >= right){
        return;
    }

    // Step 2: Pick the pivot
    // Pivot holding an address of the line so we need to declare it as array pointer
    char *pivot = v[right];

    // Step 3: Start the boundary tracker
    // Now after you decalre it pivot let set boundary for i , i need to stand BEFORE first array slot which is index0 - 1 or left - 1
    int i = left - 1;

    // Step 4: Partition — move smaller lines to the left
    /*
    Now j will start at arr[0] or left most and move right each loop and if
        - j - bigger than pivot - skip it move right the bigger one now is the left of j
        - j - smaller than pivot - i move up one arr[left - 1] now arr[0] , that arr[0] that was bigger than j now i point at it and swap that arr[bigger i] with current[j],
            so arr[ current j smaller ] will go left and the bigger i at arr[0] will be movr to the right. j ignore bigger so i can use it as stand by ready to swap right when it need to.
    Another explanation
    // j scans every slot from left to right-1.
    // - v[j] bigger than pivot: skip it. It stays behind as a "bigger" slot.
    // - v[j] smaller than pivot: i moves up one, onto the first bigger slot
    //   (or onto j itself if no bigger ones were skipped yet), then swap v[i] and v[j].
    //   The smaller one goes left, the bigger one goes right.
    // The bigger slots j skipped are exactly where i swaps into later.
    */
   for(int j = left; j < right; j++){
    if(my_strcmp(v[j], pivot) < 0){ // arr[j] - pivot < 0 mean arr[j] is smaller than pivot - swap arr[j] vs arr[i]
        i++;
        my_swap(v, i , j);
    }
   }

   // Step 5: Put the pivot in its final place
   // now after j reach the most right, for loop stop and we need to put the pivot in the middle where the left is smaller than pivot and the right is bigger than pivot.
   // To do so we need the i , because is now at the last digit of the left , all we need to do is Swap pivot's address with address of i + 1. Pivot is = right at this moment.
   my_swap(v , i + 1 , right);

   // Now is time to call our funciton inside our funnction, ITS RECURSION.

   // Now we need to declare p as new variable hold i + 1 possition.
   int p = i + 1;

   //Step 6: Sort the left part
   qsort_str(v, left, i );
   /* In this case int left is still the left
   and int right is i , because i + 1 is previous pivot location we dont touch it any more so now the new right most of left side is actually i as a new pivot
   */

   //Step 7: Sort the right part
   qsort_str(v, p + 1, right);
   /* In this case int right is still the right
   and int left is i + 2 or p + 1, because i + 1 or p is previous pivot so we dont touch previous pivot any more we move right one unit as a new left for the right side.
   */
}

/*
my_strcmp(A, B):
    receives: A and B, pointers to the two strings to compare
    returns:  an int
                negative → A comes first alphabetically
                zero     → A and B are the same
                positive → B comes first alphabetically

    loop while the character at A equals the character at B
          AND the character at A is not \0:
        move A to the next character
        move B to the next character

    the loop stopped for one of two reasons:
        1. the characters are different → their difference says which comes first
        2. both reached \0 at the same time → strings are equal, \0 - \0 = 0

    return the character at A minus the character at B
*/
int my_strcmp(char *A, char *B){
    while((*A == *B) && (*A != '\0')){
        A++;
        B++;
    }
    return *A - *B;
}

/*
my_swap(v, i, j):
    receives: v, the array of pointers (lineptr)
              i, the index of the first slot of array v
              j, the index of the second slot of array v
    returns:  nothing (void), it changes v directly

    Swap the ADDRESSES in the two slots. The strings in storage never move.

    save the address in slot i into temp   (temp is a pointer to char)
    copy the address in slot j into slot i
    copy temp into slot j

Example: v[0] → "banana", v[1] → "apple"
    temp = v[0]    temp → "banana"
    v[0] = v[1]    v[0] → "apple"
    v[1] = temp    v[1] → "banana"
*/

void my_swap(char *v[] , int i , int j){
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// ACTION 3 - writeline: print out line in storage base on the alphabetical order

/*
writelines(lineptr, nlines):
    receives: lineptr, the array of pointers (now sorted)
              nlines, how many lines to print
    returns:  nothing (void), it only prints

    for i from 0 up to nlines - 1:
        print the line in slot i, followed by a newline

    (each slot holds the address of a line in storage,
     and printf with %s follows that address and prints
     characters until it reaches \0)
*/
void writelines(char *lineptr[], int nlines){
    for(int i = 0; i <= nlines - 1; i++){
        printf("%s\n", lineptr[i]);
    }
}