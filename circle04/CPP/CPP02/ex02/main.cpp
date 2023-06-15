#include "Fixed.hpp"

int main( void ) {
    std::cout << "======PDF TEST=======" << std::endl;

    Fixed x;
    Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << x << std::endl;
    std::cout << ++x << std::endl;
    std::cout << x << std::endl;
    std::cout << x++ << std::endl;
    std::cout << x << std::endl;
    
    std::cout << y << std::endl;

    std::cout << Fixed::max( x, y ) << std::endl;

    std::cout << "======MY TEST=======" << std::endl;

    Fixed a; // Default constructor
    Fixed const b(10); // Int constructor
    Fixed const c(42.42f); // Float constructor
    Fixed const d(b); // Copy constructor

    a = Fixed(1234.4321f); // Copy assignment operator

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - c = " << a - c << std::endl;
    std::cout << "b * c = " << b * c << std::endl;
    std::cout << "a / b = " << a / b << std::endl;

    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    std::cout << "a++ is " << a++ << std::endl;
    std::cout << "a is " << a << std::endl;

    std::cout << "++a is " << ++a << std::endl;
    std::cout << "a is " << a << std::endl;

    std::cout << "a-- is " << a-- << std::endl;
    std::cout << "a is " << a << std::endl;

    std::cout << "--a is " << --a << std::endl;
    std::cout << "a is " << a << std::endl;

    return 0;
}