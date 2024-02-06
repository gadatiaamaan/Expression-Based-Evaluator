// Header file for the Subtract_Command class

#include "Subtract_Command.h"

// Constructor for Subtract_Command class
Subtract_Command::Subtract_Command(Stack<int> &s) : s_(s) {}

// Destructor for Subtract_Command class
Subtract_Command::~Subtract_Command() {}

// Method to execute subtraction operation
void Subtract_Command::execute()
{
    int a = s_.pop(), b = s_.pop();
    s_.push(b - a);
}

// Method to determine precedence of the subtraction operation
unsigned int Subtract_Command::precedence()
{
    return 2; // Subtraction has lower precedence than addition and multiplication
}
