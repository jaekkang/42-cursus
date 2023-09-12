#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {}

Fixed::Fixed(const int number) : _fixed(number << this->_literal) {}

Fixed::Fixed(const float fnumber)
    : _fixed(static_cast<float>(roundf(fnumber * (1 << this->_literal)))) {}

Fixed::Fixed(const Fixed &p) { *this = p; }

Fixed::~Fixed() {}

int Fixed::getRawBits() const { return (this->_fixed); }

void Fixed::setRawBits(const int raw) { this->_fixed = raw; }

int Fixed::toInt(void) const { return (this->_fixed >> this->_literal); }

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixed) / (1 << this->_literal);
}

Fixed &Fixed::operator=(const Fixed &p) {
    if (this != &p)
        _fixed = p.getRawBits();
    return *this;
}

Fixed Fixed::operator*(const Fixed &p) const {
    Fixed ret(this->toFloat() * p.toFloat());
    return (ret);
}

Fixed Fixed::operator/(const Fixed &p) const {
    Fixed ret(this->toFloat() / p.toFloat());
    return (ret);
}

Fixed Fixed::operator+(const Fixed &p) const {
    Fixed ret(this->toFloat() + p.toFloat());
    return (ret);
}

Fixed Fixed::operator-(const Fixed &p) const {
    Fixed ret(this->toFloat() - p.toFloat());
    return (ret);
}

bool Fixed::operator<(const Fixed &p) const {
    return (this->toFloat() < p.toFloat());
}

bool Fixed::operator<=(const Fixed &p) const {
    return (this->toFloat() <= p.toFloat());
}

bool Fixed::operator>(const Fixed &p) const {
    return (this->toFloat() > p.toFloat());
}

bool Fixed::operator>=(const Fixed &p) const {
    return (this->toFloat() >= p.toFloat());
}
bool Fixed::operator==(const Fixed &p) const {
    return (this->toFloat() == p.toFloat());
}
bool Fixed::operator!=(const Fixed &p) const {
    return (this->toFloat() != p.toFloat());
}

Fixed &Fixed::operator++(void) {
    ++this->_fixed;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed ret = *this;

    ++this->_fixed;
    return (ret);
}

Fixed &Fixed::operator--(void) {
    --this->_fixed;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed ret = *this;

    --this->_fixed;
    return (ret);
}

const Fixed &Fixed::min(Fixed &p1, Fixed &p2) {
    return (p1.getRawBits() > p2.getRawBits() ? p2 : p1);
}
const Fixed &Fixed::min(const Fixed &p1, const Fixed &p2) {
    return (p1.getRawBits() > p2.getRawBits() ? p2 : p1);
}

const Fixed &Fixed::max(Fixed &p1, Fixed &p2) {
    return (p1.getRawBits() > p2.getRawBits() ? p1 : p2);
}

const Fixed &Fixed::max(const Fixed &p1, const Fixed &p2) {
    return (p1.getRawBits() > p2.getRawBits() ? p1 : p2);
}

std::ostream &operator<<(std::ostream &os, const Fixed &p) {
    return (os << p.toFloat());
}