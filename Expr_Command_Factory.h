#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Stack.h"
#include "Add_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"
#include "Multiply_Command.h"
#include "Num_Command.h"
#include "Open_Command.h"
#include "Subtract_Command.h"

/**
 * Abstract factory for commands
 */
class Expr_Command_Factory {
public:
    Expr_Command_Factory(void) {}
    virtual ~Expr_Command_Factory(void) {};
    virtual Num_Command* create_number_command(int num) = 0;
    virtual Add_Command* create_add_command(void) = 0;
    virtual Subtract_Command* create_subtract_command(void) = 0;
    virtual Divide_Command* create_divide_command(void) = 0;
    virtual Multiply_Command* create_multiply_command(void) = 0;
    virtual Mod_Command* create_mod_command(void) = 0;
    virtual Open_Command* create_open_command(void) = 0;

private:
    // Prevent the following operations
    Expr_Command_Factory(const Expr_Command_Factory&);
    const Expr_Command_Factory& operator=(const Expr_Command_Factory&);
};

#endif
