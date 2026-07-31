/*
Practice 5.6.1 — Sort an Array of Strings

Sort the array below into alphabetic order and print the result. Sort by
rearranging the pointer array. Do not copy any string.

Use selection sort — not quicksort. The point here is the pointer handling,
not the algorithm.

Constraints:
- Write your own swap(char *v[], int i, int j)
- The strings themselves must not move
- Use strcmp for comparison, never <

Verification, and this is the real exercise:
  Print the address of each string before sorting and again after. Every
  address must be unchanged. If any address moved, you copied text somewhere.
  Use printf("%p", (void *)words[i]) to see them.

Hint, not a solution:
  Selection sort: find the smallest remaining element, swap it into position,
  repeat. The only thing that differs from the integer version is how you
  compare two elements.

  Before you write swap, work out what type temp has to be. It is not char,
  and it is not char[]. Look at what one element of words actually is.

DSA concept: comparison sort on an indirect array
Approach: selection sort over the pointer array, strcmp as the comparator
Time: O(n^2) comparisons, O(n) swaps
Space: O(1) extra — no string is duplicated

Expected output order:
  apple banana cherry date elderberry fig grape
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
/*
Selection sort:
Step 1: Find the smallest in the whole array
        Swap it into position 0
        [apple] banana cherry date

Step 2: Find the smallest in the rest (position 1 onward)
        Swap it into position 1
        apple [banana] cherry date

Step 3: Find the smallest in what's left (position 2 onward)
        Swap it into position 2
        apple banana [cherry] date

Done — the array is sorted

Pseudocode:
for (i = 0; i < n-1; i++) {
    find the smallest element from position i to the end
    let's say it's at position smallest
    swap(array, i, smallest)
}
*/

/*
In alphabetical order:

a b c d e f g h ...

"apple" comes before "banana", so "apple" is alphabetically smaller.

use strcmp to compare and dont forget to delare #include <string.h>
*/

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
    // outer loop decided what position we fill the founded element in , fill in from index 0 to 7.
    for(int i = 0; i < 7; i++){
      //inner loop to find the smalles so outer loop can fill in
      int smallest = i; // i is ASSUME to be the smallest and If function below prove i srong be replace it with the smallest on the first loop
      for(int j = i + 1; j < 7; j++){
        if(strcmp(words[j], words[smallest]) < 0){  // when strcmp run, first leter of both words[j] and words[smalles] will compare
          smallest = j;                             //strcmp(A, B) returns:
                                                    //1. negative if A comes before B alphabetically
                                                    //2. positive if A comes after B alphabetically
                                                    //3. zero if they're equal
                                                    // Order matter, if (B, A) result in opposite answer.
                                                    // ALWAY (s1, s2), so ALWAY s2 - s1 to determine return.
                                                    // first argument is what you're checking against the second.
        }
      }
      // filling in
      swap(words, i, smallest);
    } // sorting complete

    // Displace after sort
    for(int i = 0; i < 7; i++){
      printf(" %s\n", words[i]);
    }

    return 0;
}

void swap(char *v[], int i, int j){
  // temp is char* because we swapping pointer.
  char* temp = v[i]; /* put v[i] somewhere safe */
  v[i] = v[j];       /* move v[j] to v[i] */
  v[j] = temp;       /* put the saved value into v[j] */
}
/*
for comparision.
for each position i:
    set smallest = i
    for each remaining position j:
        compare words[j] to words[smallest]
        if j is alphabetically smaller:
            update smallest to j
    swap words[i] and words[smallest]
*/
/*
why strcmp(words[j], words[smallest]) < 0 ?
Because strcmp returns a number that tells you which string comes first alphabetically.

1. Negative number = first string is alphabetically before the second (comes first = is "smaller")
2. Zero = they're the same
3. Positive number = first string is alphabetically after the second (comes later = is "larger")

So when you check strcmp(words[j], words[smallest]) < 0, you're asking: "Did strcmp return a negative? Is words[j] alphabetically before words[smallest]?"

If yes, then words[j] is alphabetically smaller, so you update smallest to point at that position.
*/
/*
SUMMARY:
What You Just Did — Step by Step:
1. Set up the data — Started with 7 words in random order, stored as pointers in an array
2. Wrote the outer loop — Created a loop that runs 7 times. Each pass is responsible for putting one word in its final sorted position
3. Initialized the search — At the start of each pass, assumed the current position held the smallest word remaining
4. Wrote the inner loop — Created a second loop that scanned through all the words after the current position
5. Compared words — Used strcmp to check if any of the remaining words came before the current "smallest." If one did, updated which position held the smallest
6. Swapped into place — After scanning all remaining words, called swap() to exchange the smallest word with the word at the current position
7. Wrote the swap function — Created a function that uses a temporary char * pointer to exchange two pointers in the array
8. Added output — Wrote a print loop that shows all 7 words in their final sorted order
9. Verified — Ran the program and confirmed the output was alphabetically sorted

That's selection sort on a pointer array. The sort rearranged the pointers, not the strings themselves.
*/