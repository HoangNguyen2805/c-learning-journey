/*
Practice 4.9A - Initialization Detective

Book Level:
K&R 1.1 through 4.9 (initialization)

Problem:
This is a PREDICTION practice, not a build-from-scratch practice.
4.9 is a rules-based section - the best way to test it is predicting
behavior, then verifying against reality.

Below are FIVE numbered experiments. For EACH one:
1. WRITE YOUR PREDICTION as a comment BEFORE running
2. Compile and run
3. Compare reality to your prediction
4. Write a one-line explanation of WHY, referencing which of the
   three rules applied

The three rules:
- automatic local without init = garbage
- external without init = 0
- static without init = 0

Experiment 1: Uninitialized local
    int a;
    printf("Experiment 1: %d\n", a);

Experiment 2: External without init (declare int ext; above main)
    printf("Experiment 2: %d\n", ext);

Experiment 3: Static local without init, called 3 times
    void exp3(void) { static int s; s += 10; printf("Experiment 3: %d\n", s); }

Experiment 4: Two separate uninitialized locals in different functions
    void exp4a(void) { int x; printf("Experiment 4a: %d\n", x); }
    void exp4b(void) { int x; printf("Experiment 4b: %d\n", x); }
    Do they print the SAME garbage or DIFFERENT garbage? Predict first!

Experiment 5: Local WITH initialization inside a loop
    int i;
    for (i = 0; i < 3; i++) {
        int fresh = 100;
        fresh++;
        printf("Experiment 5: %d\n", fresh);
    }
    Does fresh print 101, 102, 103 (remembering between iterations)?
    Or 101, 101, 101 (re-initialized every iteration)?
    This tests whether a NORMAL local's "= 100" runs every loop round
    (compare with static from 4.6, which ran only once).

Program Requirements:
* Build all 5 experiments into one program.
* Write your PREDICTION comments before compiling.
* After running, add REALITY comments comparing what happened.
* Use functions and prototypes where the experiments need them (Ch.4.1).

Rules:
* No arrays.
* Predictions FIRST, then run. No fair running first.
*/
/*
#include <stdio.h>

int main() {

    return 0;
}
*/
#include <stdio.h>

// Experiment 2:
int ext;
// Experiment 3:
void exp3(void);

// Experiment 4:
void exp4a(void);    
void exp4b(void);

int main() {

    // Experiment 1: Uninitialized local
    int a;
    printf("Experiment 1: %d\n", a);
    /*
    1. Prediction: garbage/random value
    3.Output: 
    Experiment 1: 32765
    4. Rule 1: Local automatic variables = garbage if uninitialized
    */

    // Experiment 2: External without init (declare int ext; above main)
    printf("Experiment 2: %d\n", ext);
    /*
    1. Prediction: 0
    3.Output: 
    Experiment 2: 0
    4. Rule 2: External variables without initialization = automatic 0
    */

    // Experiment 3: Static local without init, called 3 times
    exp3();
    exp3();
    exp3();
    /*
    1. Prediction: 10
                   20
                   30
    3.Output: 
    Experiment 3: 10
    Experiment 3: 20
    Experiment 3: 30

    4. Rule 3: Static local variables without initialization = automatic 0 and remember their value between calls
    */

    // Experiment 4: Two separate uninitialized locals in different functions
    exp4a();    
    exp4b();
    /*
    1. Prediction: same out put on a and b but random number.
    3.Output: 
    Experiment 4a: 24165
    Experiment 4b: 24165
    4. Rule 1: Normal local automatic variables without initialization = garbage.
   They may print the same garbage by coincidence, but it is not guaranteed.
    */

    // Experiment 5: Local WITH initialization inside a loop
    int i;
    for (i = 0; i < 3; i++) {
        int fresh = 100;
        fresh++;
        printf("Experiment 5: %d\n", fresh);
    }
    /*Does fresh print 101, 102, 103 (remembering between iterations)?
    Or 101, 101, 101 (re-initialized every iteration)?
    This tests whether a NORMAL local's "= 100" runs every loop round
    (compare with static from 4.6, which ran only once).
    */

    /*
    1. Prediction: 
    101
    101
    101
    3.Output: 
    Experiment 5: 101
    Experiment 5: 101
    Experiment 5: 101
    4. Rule: A normal local variable initialized inside a loop is initialized again every loop round.
   fresh starts at 100 each iteration, then fresh++ makes it 101 every time.
    */

    return 0;
}

// Experiment 3:
void exp3(void) { 
    static int s; 
    s += 10; 
    printf("Experiment 3: %d\n", s); 
}

// Experiment 4:
void exp4a(void) { 
    int x; 
    printf("Experiment 4a: %d\n", x); 
}
    
void exp4b(void) { 
    int x; 
    printf("Experiment 4b: %d\n", x); 
}