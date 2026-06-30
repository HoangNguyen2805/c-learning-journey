/*
Practice 4.6A - Cumulative: Digit Counter Using Static Memory

Book Level:
K&R 1.1 through 4.6 Part 1 (static inside a function)

Classic DSA Problem:
Count and reverse the digits of numbers entered by the user, while
tracking - using a STATIC local variable - how many numbers have been
processed in total across the whole program run.

THE STATIC TWIST (the actual point of this practice):
You must use a STATIC local variable inside a function to count how
many numbers have been processed so far - WITHOUT using an external
variable (Ch.4.3) and WITHOUT passing a running count through
parameters/return values.

Menu:
1 - Enter a number to reverse its digits
2 - Show how many numbers have been processed so far
0 - Quit

Functions required:
* int reverseDigits(int num) -> returns num with its digits reversed
  (e.g. 1234 -> 4321), using a FOR or WHILE loop with % and / (Ch.2/3)
* void trackNumberProcessed(void) -> has NO parameters, NO return value,
  and uses a STATIC local int counter that increases by 1 every time
  it's called. It prints nothing itself - just updates its own static memory.
* int getProcessedCount(void) -> ALSO has its own STATIC local variable
  doing the SAME counting job, completely independently of
  trackNumberProcessed()'s counter (this is the deliberate trap - see below)

THE DELIBERATE TRAP:
trackNumberProcessed() and getProcessedCount() are TWO SEPARATE functions,
each with their OWN static local counter. Even though both are meant to
"count how many numbers were processed," a static local variable belongs
ONLY to the function it's declared in - it is NOT shared between
different functions, even if they're trying to track the same thing.

Predict before testing: if you call trackNumberProcessed() three times,
then call getProcessedCount() once - will getProcessedCount() report 3,
or something else? Why?

Requirements:
* reverseDigits(int num): use % to peel off the last digit, / to remove
  it, and build the reversed number digit by digit (Ch.2 arithmetic).
* Use a do-while menu (Ch.3).
* Call trackNumberProcessed() once per number successfully reversed
  (choice 1 only - not for choice 2 or invalid choices).
* Choice 2 should call getProcessedCount() and print its result, to
  reveal whether it matches trackNumberProcessed()'s count or not.

Example:
Menu:
1 - Reverse a number
2 - Show processed count
0 - Quit
Enter choice: 1
Enter a number: 1234
Reversed: 4321

Enter choice: 1
Enter a number: 500
Reversed: 5

Enter choice: 2
getProcessedCount reports: 0     <- NOT 2! This is the trap.

Why this matters (the real lesson):
A static local variable's "memory" is tied to ONE specific function.
Two different functions, even with similar-looking static counters,
do NOT share that memory. If you need TRUE shared state between
multiple functions, you need an external variable (Ch.4.3) instead.

Program Requirements:
* Use prototypes above main (Ch.4.1).
* Use a do-while menu, switch, default (Ch.3).
* reverseDigits uses a loop with % and / (Ch.2/3).
* trackNumberProcessed and getProcessedCount each use their OWN
  static local int, NOT an external variable.

Rules:
* Do not use arrays.
* Do not use an external variable for either counter - the whole
  point is proving you understand static's function-level scope.
* Try from memory first.
*/
/* Given

#include <stdio.h>

int main() {

    return 0;
}
*/

#include <stdio.h>

int processedCount = 0;   // v2 plain external - any function in this file can see it

int reverseDigits(int num);
void trackNumberProcessed(void);
int getProcessedCount(void);

int main() {

  int choice; 

  do{

    int num;

    printf("\nMenu:\n"
           "1 - Reverse a number\n"
           "2 - Show processed count\n"
           "0 - Quit\n"
           "Enter choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 0:
        printf("Quiting.\n");
        break;

      case 1:
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Reversed: %d\n", reverseDigits(num));
        trackNumberProcessed(); // v1
        processedCount++;   // v2 count this successful reversal
        break;

      case 2:
        printf("v2 = reports: %d\n", processedCount); // v2 (the correct way)
        printf("v1 = getProcessedCount reports: %d\n", getProcessedCount()); // v1
        break;

      default:
        printf("Invalid choice, try again !\n");
        break;


    }
  } while (choice != 0);

  return 0;
}

int reverseDigits(int num){
  // 1. User input will store in num.
  // 2. Each loop , we'll extract digit from right to left using 
  //                lastDigit = num % 10;
  //    EX: input = 1234, then 1234 % 10 = 123 with remainder of 4 = lastDigit
  //  Second loop =  123, then 123  % 10 = 12  with remainder of 3 = lastDigit
  //   Third loop =   12, then 12   % 10 = 1   with remainder of 2 = lastDigit
  //     Fourloop =    1, then 1    % 10 = 0   with remainder of 0 = lastDigit
  // First step, extracting user input and store it in Last digit is now done, move on to second step.
  //  Since We have everysingle input as a single digit now we need to put it together in the REVERSED way.
  //  First loop , the variable lastDigit will store the right most number of input, that number
  //               need to located at left most so to add the next last digit,
  //               we multiply that lastDigit by 10 then add the second last digit from second loop,
  //  Ex: user input = * * * 4 , reverse it to 4 * * * , so lastDigit = 4 , 
  //               if we need to add digit to the left of 4 then we need
  //                            4 * 10 + next last digit = 4 [something]
  // That 4* or 4 [something] is now store at reversed and consider as single digit for next loop, so
  //               so next loop (3rd loop) 4* will only need to multiply by 10 everyloop because:
  //                             - each loop the value after add last digit store as a single integer
  //                             - and each loop we only add one digit to the lest of that interger so 
  //                                    we only multiply whole reverse by 10 everyloop.
  // Thereforse second step we have :
  //                      reversed = reversed * 10 + lastDigit;
  // NOTE: int reversed = 0; // reverse's value will overwriten each while loop.
  // Last Step, the while loop. need to end some where and the best place to end is 
  //                      when num variable is have no more remiander, which num = 1.
  // We divided the integer num by 10 until num = 0 or something less than 1 ( ex 0.9),
  //   the reason is because the num lose 1 digit each loop so to track and count each loop,
  //   we divided num by 10 as integer because when 1 digit let /10 = decimal but integer 
  //   will skip it and make it = 0 , and thats where we violate the condition of while loop.
  // Thereforse thirdstep is :
  //                      num = num / 10;

  int lastDigit;
  int reversed = 0; // reverse's value will overwriten each while loop
  while(num != 0){
    lastDigit = num % 10;
    reversed = reversed * 10 + lastDigit;
    num = num / 10;

  }
  return reversed;
}

// This is version one v1 for choice 2, mainly for static practice lesson
// this is not the right way to but for learning purpose.
// This function will be call in case 2 loop and it can count by incrementing
//   each loop it pass by.
// why static ?
// everytime count is incrementing, it will store value regarless of 
// whatever (loop , switch , if else, ...) thing trying reset or assignt
// a different value to it, it won't reset. Value store in count forever.
// Why version 1 v1 is bad in this situation ?
//   - Lesson: static local variables are NOT shared between functions, 
//             even with the same name
// Even those 2 function have the same variable count.
//   - trackNumberProcessed's count variable is to store value.
//   - getProcessedCount's count is to return value that store in count.
//   That was the plan but it not how it work because static local variables 
//        are NOT shared between functions, even with the same name
void trackNumberProcessed(void){ // v1
  static int count = 0;
  count++;
} // no return needed - void

int getProcessedCount(void){
  static int count = 0;
  return count; 
} // must return, since this is how main() gets the value