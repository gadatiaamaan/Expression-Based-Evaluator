// Calculator source File
#include "Calculator.h"

// Adds a command to the postfix array
void Calculator::add_command(Expr_Command* com, Array<Expr_Command*>& postfix, int& postfix_idx) {
    // Increment the postfix index
    postfix_idx++;

    // Resize the postfix array if necessary
    if (postfix_idx >= (int)postfix.size()) {
        postfix.resize(postfix.size() * 2);
    }

    // Add the command to the postfix array
    postfix[postfix_idx] = com;
}

// Converts the space-delimited infix expression to a postfix format
int Calculator::infix_to_postfix(const std::string& infix, Expr_Command_Factory& factory, Array<Expr_Command*>& postfix, int& postfix_idx) {
    // Initialize variables
    std::istringstream input(infix);
    std::string token;
    Expr_Command* cmd;
    Stack<Expr_Command*> temp;
    postfix_idx = -1;

    // Loop through the input stream until end of file
    while (!input.eof()) {
        // Read the next token
        input >> token;

        // Create appropriate command based on token
        if (is_int(token)) {
            cmd = factory.create_number_command(std::stoi(token));
        } else if (token == "+") {
            cmd = factory.create_add_command();
        } else if (token == "-") {
            cmd = factory.create_subtract_command();
        } else if (token == "/") {
            cmd = factory.create_divide_command();
        } else if (token == "*") {
            cmd = factory.create_multiply_command();
        } else if (token == "%") {
            cmd = factory.create_mod_command();
        } else if (token == "(") {
            temp.push(factory.create_open_command());
            continue;
        } else if (token == ")") {
            // Pop operators from the stack until an open parenthesis is encountered
            while (!temp.is_empty() && temp.top()->precedence() != 1) {
                add_command(temp.pop(), postfix, postfix_idx);
            }

            // Delete the open parenthesis command
            delete temp.top();
            temp.pop();
            continue;
        } else {
            // Print error message for invalid token
            std::cerr << "Invalid token: " << token << "\n";
            return 0; // Return 0 indicating error
        }

        // If the command has precedence 0 (number), add it to the postfix array and continue
        if (cmd->precedence() == 0) {
            add_command(cmd, postfix, postfix_idx);
            continue;
        }
        
        // While the temporary stack is not empty and the precedence of the command is less than or equal to the precedence of the top command in the stack,
        // pop commands from the stack and add them to the postfix array
        while (!temp.is_empty() && cmd->precedence() <= temp.top()->precedence()) {
            add_command(temp.pop(), postfix, postfix_idx);
        }
        // Push the current command onto the temporary stack
        temp.push(cmd);
    }

    // After processing all tokens, add any remaining commands from the temporary stack to the postfix array
    while (!temp.is_empty()) {
        add_command(temp.pop(), postfix, postfix_idx);
    }

    // Return 1 indicating successful conversion
    return 1;
}

// Evaluate the list of commands in postfix order
void Calculator::evaluate_postfix(Array<Expr_Command*> commands, int idx) {
    for (int i = 0; i <= idx; i++) {
        Expr_Command* cmd = commands[i];
        cmd->execute();
        delete cmd;
    }
}

// Evaluate the infix style user input and return the result
int Calculator::evaluate_input(const std::string input, int& output) {
    // Initialize a stack for numbers, a factory for creating commands, and an array for postfix commands
    Stack<int> nums;
    nums.push(0);
    Stack_Expr_Command_Factory factory(nums);
    Array<Expr_Command*> postfix(10);
    int postfix_idx;

    // Convert infix expression to postfix
    if (!infix_to_postfix(input, factory, postfix, postfix_idx)) {
        return 0; // Return 0 indicating error in conversion
    }

    // Evaluate the postfix expression
    evaluate_postfix(postfix, postfix_idx);
    // Set the output to the top value in the numbers stack
    output = nums.top();
    // Return 1 indicating successful evaluation
    return 1;
}
