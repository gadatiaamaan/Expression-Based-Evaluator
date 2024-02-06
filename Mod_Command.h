#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

// Mod_Command class declaration
class Mod_Command : public Expr_Command {
public:
    // Constructor
    Mod_Command(Stack<int> &s);

    // Destructor
    ~Mod_Command();

    // Execute method
    void execute();

    // Precedence method
    unsigned int precedence();

private:
    // Reference to the stack
    Stack<int> &s_;
};

#endif
