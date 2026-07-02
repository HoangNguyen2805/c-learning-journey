// Finishing structure 

#include <stdio.h>

// prototypes for the functions the experiments need
void exp3(void);
void exp4a(void);
void exp4b(void);

int ext;   // Experiment 2 needs this external variable

int main() {
    // === Experiment 1: uninitialized local ===
    // MY PREDICTION: prints garbage, unpredictable
    int a;
    printf("Experiment 1: %d\n", a);

    // === Experiment 2: external without init ===
    // MY PREDICTION: prints 0
    printf("Experiment 2: %d\n", ext);

    // === Experiment 3: static local, called 3 times ===
    // MY PREDICTION: 10, 20, 30
    exp3();
    exp3();
    exp3();

    // === Experiment 4: two separate uninitialized locals ===
    // MY PREDICTION: ??? same or different garbage?
    exp4a();
    exp4b();

    // === Experiment 5: local WITH init inside a loop ===
    // MY PREDICTION: ??? 101,102,103 or 101,101,101?
    int i;
    for (i = 0; i < 3; i++) {
        int fresh = 100;
        fresh++;
        printf("Experiment 5: %d\n", fresh);
    }

    return 0;
}

void exp3(void) {
    static int s;
    s += 10;
    printf("Experiment 3: %d\n", s);
}

void exp4a(void) {
    int x;
    printf("Experiment 4a: %d\n", x);
}

void exp4b(void) {
    int x;
    printf("Experiment 4b: %d\n", x);
}