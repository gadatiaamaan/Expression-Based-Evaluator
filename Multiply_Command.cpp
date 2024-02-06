// Multiply_Command Source file
#include "Multiply_Command.h"

Multiply_Command::Multiply_Command(Stack<int> &s) : s_(s) {}

Multiply_Command::~Multiply_Command(void) {}

void Multiply_Command::execute(void)
{
    int a = s_.pop(), b = s_.pop();
    s_.push(a * b);
}

unsigned int Multiply_Command::precedence(void)
{
    return 3;
}
