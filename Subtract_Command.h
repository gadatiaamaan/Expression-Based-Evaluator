#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Subtract_Command : public Expr_Command {
public:
    Subtract_Command(Stack<int> &s); // Constructor
    ~Subtract_Command(); // Destructor

    void execute(); // Execute the subtraction operation

    unsigned int precedence(); // Determine the precedence of the subtraction operator

private:
    Stack<int> &s_; // Reference to the stack for performing the operation
};

#endif
