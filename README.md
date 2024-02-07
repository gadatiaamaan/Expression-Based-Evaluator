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

## Technologies, Algorithms, and Concepts Used

### Technologies:

- **C++**: The primary programming language used for implementing the expression evaluator. C++ provides features such as classes, templates, and standard libraries necessary for developing complex data structures and algorithms.

### Data Structures:

- **Stack**: Implemented using the Array class to handle the conversion of infix expressions to postfix notation and the evaluation of postfix expressions. The stack data structure enables efficient handling of operators and operands during expression evaluation.

### Design Patterns:

- **Command Pattern**: Utilized for evaluating postfix expressions. The Command Pattern decouples the request for evaluating commands from the execution of those commands, allowing for flexibility and extensibility in handling different types of expressions and operations.

- **Abstract Factory Pattern**: Employed for creating commands based on parsing the infix expression. The Abstract Factory Pattern provides an interface for creating families of related objects without specifying their concrete classes, facilitating the creation of command objects dynamically based on the input expression.

### Algorithms:

- **Infix to Postfix Conversion**: Implemented using the shunting-yard algorithm to convert infix expressions to postfix notation. The algorithm iterates through the input expression, pushing operators onto a stack while maintaining their precedence and associativity, resulting in a postfix expression suitable for evaluation.

- **Postfix Expression Evaluation**: Employed a straightforward algorithm to evaluate postfix expressions. The program iterates through the postfix expression, pushing operands onto a stack and performing operations when encountering operators, resulting in the final result of the expression.

### Concepts:

- **Expression Parsing**: Involves breaking down the input infix expression into tokens and interpreting them to construct the corresponding postfix expression. Expression parsing enables the program to handle complex mathematical expressions and operators in a structured manner.

- **Object-Oriented Design**: Utilized object-oriented principles such as encapsulation, inheritance, and polymorphism to design and implement modular, reusable, and maintainable code for the expression evaluator program. Object-oriented design enhances code organization and facilitates future enhancements and modifications.