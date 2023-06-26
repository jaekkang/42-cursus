#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

class Point {
 private:
  const Fixed _x;
  const Fixed _y;

 public:
  Point();
  Point(Fixed x, Fixed y);
  Point(const Point &p);
  Point &operator=(const Point &p);
  ~Point();

  const Fixed &getX() const;
  const Fixed &getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif