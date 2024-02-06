#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

/**
 * Concrete factory for commands
 */
class Stack_Expr_Command_Factory : public Expr_Command_Factory {
public:
    Stack_Expr_Command_Factory(Stack<int> &stack);
    ~Stack_Expr_Command_Factory();
    virtual Num_Command *create_number_command(int num);
    virtual Add_Command *create_add_command();
    virtual Subtract_Command *create_subtract_command();
    virtual Divide_Command *create_divide_command();
    virtual Multiply_Command *create_multiply_command();
    virtual Mod_Command *create_mod_command();
    virtual Open_Command *create_open_command();

private:
    Stack<int> &stack_;
};

#endif
