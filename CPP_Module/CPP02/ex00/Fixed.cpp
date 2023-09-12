#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &p) {
    std::cout << "Copy constructor called" << std::endl;
    *this = p;
}

Fixed &Fixed::operator=(const Fixed &p) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &p) {
        this->setRawBits(p.getRawBits());
    }
    return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits(const int raw) { this->_fixed = raw; }

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}
