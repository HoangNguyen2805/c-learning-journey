/*
Practice 01 - Cumulative Switch Challenge

Book Level:
K&R 1.1 through 3.4

Problem:
Build a simple campus meal kiosk program.

The customer will choose ONE item from the menu.

The program should ask the user for:

* menu choice
* quantity of that one item
* student type

Important:
This program does NOT allow multiple different items yet.

Example allowed:

* 3 coffees
* 2 pizzas
* 1 burger

Example not allowed yet:

* 2 coffees and 3 pizzas in the same order

Then the program should calculate and print a receipt.

Menu:
A - Burger       $8.50
B - Pizza        $7.25
C - Salad        $6.75
D - Coffee       $3.50

Student Type:
F = full-time student
P = part-time student
N = not a student

Discounts:
F = 15%
P = 10%
N = 0%

Program Requirements:

* Use scanf to get input from the user.
* Use switch to choose the food price.
* Use quantity to calculate the subtotal.
* Use default for invalid menu choices.
* Use break after every case.
* Use if / else-if / else to choose the discount.
* Use arithmetic to calculate subtotal, discount, and total.
* Print a clean receipt.

Required Skills:

* printf
* scanf
* variables
* int
* double
* char
* arithmetic
* if / else-if / else
* switch
* case
* break
* default
* comments

Rules:

* Customer can order only one item type.
* Customer can enter quantity for that item.
* Do not allow multiple different items yet.
* Do not use loops.
* Do not use arrays.
* Do not use functions yet.
* Do not copy an answer.
* Try from memory first.
  */


#include <stdio.h>

int main() {

   char menuChoice;
   char studentType;
   double price;
   int quantity;
   double discount;
   double subtotal;
   double discountAmount;
   double finalPrice;

   printf("Campus meal kiosk program.\n"
      "\nMenu:\n"
      "A - Burger.......$8.50\n"
      "B - Pizza........$7.25\n"
      "C - Salad........$6.75\n"
      "D - Coffee.......$3.50\n");
   printf("Enter here: ");
   scanf(" %c", &menuChoice);
   printf("Quantity: ");
   scanf(" %d", &quantity);

   printf("\nDiscounts:\n"
         "F = 15%%\n"
         "P = 10%%\n"
         "N = 0%%\n");

   printf("\nStudent Type:\n"
      "F = full-time student\n"
      "P = part-time student\n"
      "N = not a student\n");
   printf("Enter here: ");
   scanf(" %c", &studentType);

   switch (menuChoice) {
      case 'A':
         price = 8.50;
         break;

      case 'B':
         price = 7.25;
         break;

      case 'C':
         price = 6.75;
         break;

      case 'D':
         price = 3.50;
         break;

      default:
         printf("Invalid choice, please try again !\n");
   }

   if (studentType == 'F') {
      discount = 0.15;
   } else if (studentType == 'P') {
      discount = 0.1;
   } else if (studentType == 'N') {
      discount = 0;
   } else {
      printf("Invalid student type, try again!\n");
      return 0;
   }

   subtotal = price * quantity;
   discountAmount = subtotal * discount;
   finalPrice = subtotal - discountAmount;

   printf("\nSubtotal: $%.2f\n", subtotal);
   printf("Discount: $%.2f\n", discountAmount);
   printf("Total: $%.2f\n", finalPrice);

   return 0;
}
