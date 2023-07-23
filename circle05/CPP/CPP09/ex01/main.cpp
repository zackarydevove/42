#include <iostream>
#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc == 2) 
    {
        RPN rpn;
        try {
            int result = rpn.evaluate(argv[1]);
            std::cout << result << '\n';
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
    else
        std::cerr << "Usage: ./RPN <expression>\n";
    return 0;
}