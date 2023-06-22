#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN();
    RPN(const RPN&);
    ~RPN();
    RPN& operator=(const RPN&);

    int evaluate(const std::string& expression);
};

#endif