/*Practice 2.
Use variables to print your own profile:

Required variables:

char name[] = "Hoang";
int age = 25;
char favoriteLetter = 'H';
float gasPrice = 2.89;
double bankBalance = 1234.56;
bool likesC = true;

Expected output:

Name: Hoang
Age: 25
Favorite letter: H
Gas price: 2.89
Bank balance: 1234.56
Likes C: 1

Compile/run:

gcc practice02_personal_profile.c -o practice02
./practice02
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    char name[] = "Hoang";
    int age = 25;
    char favoriteletter = 'H';
    float gasPrice = 2.89;
    double bankBalance = 1234.56;
    bool likesC = true;

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Favorite letter: %c\n", favoriteletter);
    printf("Gas price: %.2f\n", gasPrice);
    printf("Bank balance: %.2f\n", bankBalance);
    printf("Likes C: %d\n", likesC);

    return 0;
}