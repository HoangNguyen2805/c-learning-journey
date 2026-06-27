// NOTE: This uses arrays (val[]), which I haven't learned yet.
// Revisit and fully understand this once Chapter 5 (arrays) is done.
#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f);
double pop(void);

int main() {
    double a;
    double b;

    push(10.0);
    push(20.0);
    push(30.0);

    a = pop();
    b = pop();

    printf("First pop: %.1f\n", a);
    printf("Second pop: %.1f\n", b);

    return 0;
}

void push(double f) {
    if (sp < MAXVAL) {
        val[sp] = f;
        sp++;
    }
    else {
        printf("Error: stack full\n");
    }
}

double pop(void) {
    if (sp > 0) {
        sp--;
        return val[sp];
    }
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}