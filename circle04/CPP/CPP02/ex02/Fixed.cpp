#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) { }

Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits) { }

Fixed::Fixed(const float floatValue) : _fixedPointValue(roundf(floatValue * (1 << _fractionalBits))) { }

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) { }

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() {
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_fixedPointValue;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPointNumber) {
    out << fixedPointNumber.toFloat();
    return out;
}