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

/*
Compile

Commands are:
``
gcc lesson01_hello.c -o lesson01
./lesson01
``

Now we compile and run the program using command. A compiler is a translator that converts 
the human-readable C code into machine code (binary 01001010) that the computer can execute.

In terminal type: gcc lesson01_hello.c -o lesson01
         where:
         - gcc = C compiler command
         - lesson01_hello.c     = input C file
         - lesson01_hello.c = the C file's name that we want to compile
         - -o = output name, name of the exe file that create after compile the source code.

gcc lesson01_hello.c -o lesson01 -> gcc, compile lesson01_hello.c and name the created program lesson01

A compiler turn this 
        C code humans can read
                 into
        a program the computer can run

So the flow is 
- lesson01_hello.c → gcc → lesson01

What is lesson01?
After compile the source code (lesson01_hello.c)
We get an executable program name (lesson01) that we can run on our computer. 
When we run lesson01, it will execute the instructions in the original C code and produce the output we expect.

What is ./ in ./lesson01?
This command: ./ mean -> look in the current folder for the executable file named lesson01 and run it.
So ./lesson01 mean look inside lesson01's folder and run the lesson01 program.
*/