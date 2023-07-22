#include "Span.hpp"

Span::Span() {};

Span::Span(unsigned int maxSize): _maxSize(maxSize), _numbers(0) { }

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
    _numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is already full");
    for (std::vector<int>::iterator it = begin; it != end; it++)
        addNumber(*it);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers in the Span to find a span");

    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());

    int shortest = INT_MAX;
    for (std::vector<int>::iterator it = copy.begin(); it + 1 != copy.end(); ++it) {
        int diff = *(it + 1) - *it;
        if (diff < shortest) {
            shortest = diff;
        }
    }

    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers in the Span to find a span");

    return *(std::max_element(_numbers.begin(), _numbers.end())) - *(std::min_element(_numbers.begin(), _numbers.end()));
}