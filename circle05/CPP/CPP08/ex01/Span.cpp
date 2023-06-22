#include "Span.hpp"

Span::Span(unsigned int maxSize): _maxSize(maxSize) { }

Span::Span(const Span& other): _maxSize(other._maxSize), _numbers(other._numbers) { }

Span::~Span() { }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is already full");
    _numbers.insert(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
        throw std::runtime_error("Adding these numbers would exceed the maximum size of the Span");
    _numbers.insert(begin, end);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers in the Span to find a span");

    std::multiset<int>::iterator it = _numbers.begin();
    std::multiset<int>::iterator next = it;
    ++next;

    int shortestSpan = INT_MAX;
    for (; next != _numbers.end(); ++it, ++next) {
        int span = *next - *it;
        if (span < shortestSpan)
            shortestSpan = span;
    }
    return shortestSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers in the Span to find a span");

    return *(_numbers.rbegin()) - *(_numbers.begin());
}