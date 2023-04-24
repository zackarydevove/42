#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed(); // default constructor
        Fixed(const Fixed& other); // copy constructor
        Fixed& operator=(const Fixed& other); // copy assignment operator
        ~Fixed(); // destructor

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif`