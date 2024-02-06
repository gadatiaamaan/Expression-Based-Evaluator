#include "Add_Command.h"

// Constructor for Add_Command class
Add_Command::Add_Command(Stack<int> &s) : s_(s) {}

// Destructor for Add_Command class
Add_Command::~Add_Command() {}

// Execute method for Add_Command class
void Add_Command::execute() {
    // Pop two elements from the stack
    int a = s_.pop();
    int b = s_.pop();
    
    // Push the result of addition back onto the stack
    s_.push(a + b);
}

// Precedence method for Add_Command class
unsigned int Add_Command::precedence() {
    // Addition has a precedence of 2
    return 2;
}
