#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

// Include necessary header files
#include "Expr_Command.h"
#include "Stack.h"

// Add_Command header file

// Add command class
class Add_Command : public Expr_Command {
public:
    // Constructor
    Add_Command(Stack<int> & s);
    
    // Destructor
    ~Add_Command();
    
    // Execute the add command
    void execute();
    
    // Get the precedence of the add command
    unsigned int precedence();

private:
    // Reference to the stack
    Stack<int> & s_;
};

#endif
