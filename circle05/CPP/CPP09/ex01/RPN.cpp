#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cstdlib>

RPN::RPN() { }

RPN::RPN(const RPN&) { }

RPN& RPN::operator=(const RPN&) { return *this; }

RPN::~RPN() { }

int RPN::evaluate(const std::string& expression) {
    std::stack<int> stk;

    for (size_t i = 0; i < expression.size(); ++i) {
        char token = expression[i];
        if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            if (stk.size() < 2)
                throw std::runtime_error("Invalid RPN expression: not enough operands");
            int op2 = stk.top(); stk.pop();
            int op1 = stk.top(); stk.pop();

            if (token == '+')
                stk.push(op1 + op2);
            else if (token == '-')
                stk.push(op1 - op2);
            else if (token == '*')
                stk.push(op1 * op2);
            else if (token == '/')
            {
                if (op2 == 0)
                    throw std::runtime_error("Invalid RPN expression: division by zero");
                stk.push(op1 / op2);
            }
        }
        else if (isdigit(token))
            stk.push(token - '0');
        else if (!isspace(token))
            throw std::runtime_error("Invalid RPN expression: invalid token");

    }

    if (stk.size() != 1)
        throw std::runtime_error("Invalid RPN expression: too many operands");

    return stk.top();
}