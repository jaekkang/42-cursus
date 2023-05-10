#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : _fixed(number << this->_literal) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fnumber)
    : _fixed(static_cast<float>(roundf(fnumber * (1 << this->_literal)))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &p) {
    std::cout << "Copy constructor called" << std::endl;
    *this = p;
}

Fixed &Fixed::operator=(const Fixed &p) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &p)
        _fixed = p.getRawBits();
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const { return (this->_fixed); }

void Fixed::setRawBits(const int raw) { this->_fixed = raw; }

int Fixed::toInt(void) const { return (this->_fixed >> this->_literal); }

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixed) / (1 << this->_literal);
}

std::ostream &operator<<(std::ostream &os, const Fixed &p) {
    return (os << p.toFloat());
}