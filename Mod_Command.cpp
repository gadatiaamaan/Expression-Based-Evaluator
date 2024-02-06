#include "Mod_Command.h"

// Constructor
Mod_Command::Mod_Command(Stack<int> &s) : s_(s) {}

// Destructor
Mod_Command::~Mod_Command() {}

// Execute command
void Mod_Command::execute()
{
    int a = s_.pop();
    int b = s_.pop();
    s_.push(b % a);
}

// Return precedence
unsigned int Mod_Command::precedence()
{
    return 3;
}
