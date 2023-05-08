#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed(); // default constructor
        Fixed(const int intValue); // integer constructor
        Fixed(const float floatValue); // float constructor
        Fixed(const Fixed& other); // copy constructor
        Fixed& operator=(const Fixed& other); // copy assignment operator
        ~Fixed(); // destructor

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPointNumber);

#endif