#include <string>
#include <iostream>
#include "Calculator.h"

int main(int argc, char * argv[]) {
    std::string input;

    // Input loop
    while (true) {
        std::cout << "Enter an expression in Infix format: ";
        std::getline(std::cin, input);
        input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
        std::cout << "\n";

        // If QUIT is entered, quit
        if (!input.compare("QUIT")) {
            break;
        }

        int result;
        if (Calculator::evaluate_input(input, result)) {
            std::cout << "Result: " << result << "\n";
        } else {
            std::cout << "Failed to compute\n";
        }
    }

    return 0;
}
