// Divide_Command header file

#include "Divide_Command.h"

Divide_Command::Divide_Command(Stack<int> &s) : s_(s) {}

Divide_Command::~Divide_Command() {}

void Divide_Command::execute()
{
    int a = s_.pop(), b = s_.pop();
    s_.push(b / a);
}

unsigned int Divide_Command::precedence()
{
    return 3;
}
