#include <stdio.h> // This line give your program access to basic input/output tools.
                   // basic input/output tools include functions like printf() and scanf().
                   // stdio.h stands for "standard input/output header".
                   // remeber that "If I use printf, I need #include <stdio.h>"
 
int main() 
    // main is where the program starts. When the pogram runs, C is scanding from top to 
    // bottom and look for main function to start with.
    // Every C program need main function.
{ // The curly braces {} contain the body of the function.
            /* { = Start
               } = End
               Everything inside { } is belong to the main function.
            */
    printf("Hello, C!\n");
    // printf() = print text to the screen. The text go in single or double quotes " text here ". 
    //The \n = new line. Current row text is end here before \n and everyuthing 
    //after \n will be in the next line or row.
    printf("My name is Hoang.\n");// -> " ; " is a semicolon. Every normal C statement end with ; semeicolon.
    printf("I am learning C for LeetCode.\n"); // semicolon like a period in English
    printf("Today is Day 01.\n"); // ; -> This command is finished.
    
    // Output:
    /*Hello, C!
    My name is Hoang.
    I am learning C for LeetCode.
    Today is Day 01.
    */

    return 0; // return 0; -> mean the program finish successfully.
              // If you return 0, it means the program finished successfully.
              // If you return a non-zero value, it means the program finished with an error.
}