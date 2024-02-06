// Num_Command header file

#include "Num_Command.h"

// Constructor
Num_Command::Num_Command(Stack<int> & s, int n) : s_(s), n_(n) {}

// Destructor
Num_Command::~Num_Command(void) {}

// Execute command
void Num_Command::execute(void)
{
    s_.push(this->n_);
}

// Get precedence of command
unsigned int Num_Command::precedence(void)
{
    return 0;
}
