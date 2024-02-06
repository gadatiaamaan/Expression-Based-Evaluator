// Calculator header file

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Stack_Expr_Command_Factory.h"
#include "Stack.h"
#include <string>
#include <sstream>
#include <regex>

class Calculator
{
public:
    // Evaluate the infix style user input and return the result.
    // @param input string value of user input
    // @param output output of the calculation. 0 if there was an error.
    // @return 1 if the calculation was performed successfully. 0 if there was an error
    static int evaluate_input(const std::string input, int &output);

private:
    // Convert the space-delimited infix expression to a postfix format.
    // @param infix infix expression represented as a space-delimited string
    // @param factory factory for creating commands
    // @param postfix array of postfix commands
    // @param postfix_idx index of the final postfix command
    // @returns 1 if the conversion was successful. 0 if there was an error.
    static int infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command*> &postfix, int &postfix_idx);

    // Evaluate the list of commands in postfix order
    // @param commands array of commands in postfix order
    // @param idx index of of the final command in the postfix array
    static void evaluate_postfix(Array<Expr_Command*> commands, int idx);

    // Add a command to the postfix array
    // @param com command to add
    // @param postfix postfix array
    // @param postfix_idx postfix_idx
    static void add_command(Expr_Command* com, Array<Expr_Command*> &postfix, int &postfix_idx);

    // Determine if the entered string is an integer.
    // @param str string to analyze
    // @returns true if the string is an integer, false otherwise
    static bool is_int(const std::string str);
};

#include "Calculator.inl"

#endif
