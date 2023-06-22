#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cstdlib>

RPN::RPN() { }

RPN::RPN(const RPN&) { }

RPN& RPN::operator=(const RPN&) {
    return *this;
}

RPN::~RPN() { }

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<int> stk;
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stk.size() < 2)
                throw std::runtime_error("Invalid RPN expression: not enough operands");
            int op2 = stk.top(); stk.pop();
            int op1 = stk.top(); stk.pop();

            if (token == "+") stk.push(op1 + op2);
            else if (token == "-") stk.push(op1 - op2);
            else if (token == "*") stk.push(op1 * op2);
            else if (token == "/") {
                if (op2 == 0)
                    throw std::runtime_error("Invalid RPN expression: division by zero");
                stk.push(op1 / op2);
            }
        } else {
            stk.push(std::atoi(token.c_str()));
        }
    }

    if (stk.size() != 1)
        throw std::runtime_error("Invalid RPN expression: too many operands");

    return stk.top();
}