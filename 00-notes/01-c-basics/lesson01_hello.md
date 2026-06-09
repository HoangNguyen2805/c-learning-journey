# Day 01 - Hello World and Compile

## Big idea

C does not run directly.

The workflow is:

write code -> save -> compile -> run

## Source code vs executable

lesson01_hello.c = source code file I write.

lesson01 = executable program created by gcc.

## Code meaning

#include <stdio.h>

This gives my program access to standard input/output tools.

stdio.h means standard input/output header.

Important tools from stdio.h:
- printf() prints output
- scanf() reads input

For now, I need to remember:

If I use printf, I need #include <stdio.h>.

## main function

int main()

main is where a normal C program starts.

Every normal C program needs a main function.

## Curly braces

{
}

Curly braces contain the body of the function.

{ means start.
} means end.

Everything inside the braces belongs to the function.

## printf

printf() prints text to the screen.

Example:

printf("Hello, C!\n");

The text for printf should use double quotes.

\n means new line.

## Semicolon

Every normal C statement ends with a semicolon.

Example:

printf("Hello, C!\n");

The semicolon means this command is finished.

## return 0

return 0;

This means the program finished successfully.

A non-zero return value usually means the program ended with an error.

## Compile command

gcc lesson01_hello.c -o lesson01

Meaning:
- gcc = C compiler
- lesson01_hello.c = input C file
- -o = output name
- lesson01 = name of the executable program created

## Run command

./lesson01

Meaning:
- ./ means current folder
- lesson01 is the program I want to run

So ./lesson01 means run the lesson01 program from the current folder.

## Output

Hello, C!
My name is Hoang.
I am learning C for LeetCode.
Today is Day 01.

## What I need to remember

C cycle:

edit code -> save -> compile -> run

Important command:

gcc lesson01_hello.c -o lesson01
./lesson01