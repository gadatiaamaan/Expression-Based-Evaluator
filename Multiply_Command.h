#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Multiply_Command : public Expr_Command {
public:
    Multiply_Command(Stack<int> &s);
    ~Multiply_Command();

    void execute();

    // Returns the precedence of the multiply command
    unsigned int precedence();

private:
    Stack<int> &s_;
};

#endif
