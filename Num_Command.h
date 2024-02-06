#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

// Number command. Adds a number to the stack.
class Num_Command : public Expr_Command {
public:
    Num_Command(Stack<int> &s, int n);
    ~Num_Command();

    void execute();

    unsigned int precedence();

private:
    Stack<int> &s_;
    int n_;
};

#endif
