#include "Stack_Expr_Command_Factory.h"

// Stack Expressions and Command Factory Source

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack<int> &stack) : stack_(stack)
{
    stack_ = stack;
}

// Concrete methods

Num_Command *Stack_Expr_Command_Factory::create_number_command(int num)
{
    return new Num_Command(stack_, num);
}

Add_Command *Stack_Expr_Command_Factory::create_add_command()
{
    return new Add_Command(stack_);
}

Subtract_Command *Stack_Expr_Command_Factory::create_subtract_command()
{
    return new Subtract_Command(stack_);
}

Divide_Command *Stack_Expr_Command_Factory::create_divide_command()
{
    return new Divide_Command(stack_);
}

Multiply_Command *Stack_Expr_Command_Factory::create_multiply_command()
{
    return new Multiply_Command(stack_);
}

Mod_Command *Stack_Expr_Command_Factory::create_mod_command()
{
    return new Mod_Command(stack_);
}

Open_Command *Stack_Expr_Command_Factory::create_open_command()
{
    return new Open_Command();
}
