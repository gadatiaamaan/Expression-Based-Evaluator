# Expression Evaluator Program

## Overview
This program implements a basic expression evaluator in C++. It utilizes the Stack data structure implemented using the Array class to convert infix expressions to postfix notation and then evaluate them. The program also incorporates design patterns such as the Command Pattern for evaluating postfix expressions and the Abstract Factory Pattern for creating commands based on parsing the infix expression.

## Features
- Converts infix expressions to postfix notation.
- Evaluates postfix expressions using the Command Pattern.
- Handles operators (+, -, /, *, %), parentheses, and integers (positive and negative).
- Accepts input from STDIN and outputs results to STDOUT.
- The program runs continuously until the user enters "QUIT" (in all caps).

## Usage
### Compilation
Compile the program using the `make` command.
   `make`


### Execution
Run the program with the following command:
    `./calculator`

### Quitting
To quit the program, enter `QUIT` (in all caps) when prompted for input.
    `QUIT`

## Runtime Requirements
- C++ compiler
- Standard input/output streams
- POSIX-compatible operating system for `make` command (optional)

