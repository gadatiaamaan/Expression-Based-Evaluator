#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

// Command base class
class Expr_Command {
public:
    virtual void execute() = 0; // Executes the command
    virtual ~Expr_Command() = default; // Destructor
    virtual unsigned int precedence() = 0; // Determines the precedence of the command
};

#endif
