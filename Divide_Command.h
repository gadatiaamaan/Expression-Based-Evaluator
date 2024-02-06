// Divide_Command header file

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

// Divide command class
class Divide_Command : public Expr_Command {
public:
    // Constructor
    Divide_Command(Stack<int> &s);

    // Destructor
    ~Divide_Command();

    // Execute the division operation
    void execute();

    // Get the precedence of the division operator
    unsigned int precedence();

private:
    // Reference to the stack
    Stack<int> &s_;
};

#endif
