#ifndef _OPEN_COMMAND_H_
#define _OPEN_COMMAND_H_

#include "Expr_Command.h"

class Open_Command : public Expr_Command {
public:
    // Constructor
    Open_Command(void);

    // Destructor
    ~Open_Command(void);

    // Execute command
    void execute(void);

    // Get precedence
    unsigned int precedence(void);
};

#endif
