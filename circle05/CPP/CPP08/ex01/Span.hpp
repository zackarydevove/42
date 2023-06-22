#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::multiset<int> _numbers;

public:
    Span(unsigned int maxSize);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    void addNumber(int number);

    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    
    int shortestSpan() const;
    int longestSpan() const;
};

#endif