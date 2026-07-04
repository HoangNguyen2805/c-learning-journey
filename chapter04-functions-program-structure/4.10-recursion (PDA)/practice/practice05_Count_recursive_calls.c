/*
### Problem 5 - Count recursive calls (instrumentation)

Take your `gcd` function from Problem 3 and modify it to also count how
many recursive calls it makes for a given input, using a `static` local
variable inside the function (remember `static` from 4.6/4.9 — it
remembers its value between calls).

Print how many calls `gcd(48, 18)` took in total. Predict a rough number
before running — doesn't have to be exact, just get in the right
ballpark.
*/
#include <stdio.h>

int gcd(int a, int b);

int main(){

    int a;
    int b;
    printf("Find GCD(a,b)\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    
    printf("Result = %d\n", gcd(a,b));

    return 0;
}

int gcd(int a, int b){

    static int callCount = 0;    // Declare and initialize at the top, once
    callCount++;                  // Increment each time the function is called 

    if (b == 0){
        printf("It took %d call in total.\n", callCount);
        return a;
    }else{
        int remainder = a % b;
        return gcd(b, remainder);
    }
}