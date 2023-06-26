#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &p) {
  if (this != &p) {
    const_cast<Fixed &>(this->_x) = const_cast<Fixed &>(p.getX());
    const_cast<Fixed &>(this->_y) = const_cast<Fixed &>(p.getY());
  }
}

Point &Point::operator=(const Point &p) {
  if (this != &p) {
    const_cast<Fixed &>(this->_x) = const_cast<Fixed &>(p.getX());
    const_cast<Fixed &>(this->_y) = const_cast<Fixed &>(p.getY());
  }
  return *this;
}

Point::~Point() {}

const Fixed &Point::getX() const { return _x; }

const Fixed &Point::getY() const { return _y; }