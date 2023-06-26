#include "Point.hpp"

static int lineCheck(Point const p, Point const a, Point const b) {
  Fixed zero = Fixed();
  Fixed ans = (p.getX() - a.getX()) * (a.getY() - b.getY()) -
              (p.getY() - a.getY()) * (a.getX() - b.getX());

  if (ans > zero)
    return (1);
  else if (ans < zero)
    return (-1);
  return (0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  if (lineCheck(point, a, b) != lineCheck(c, a, b) ||
      lineCheck(point, a, b) == 0)
    return false;
  if (lineCheck(point, a, c) != lineCheck(b, a, c) ||
      lineCheck(point, a, c) == 0)
    return false;
  if (lineCheck(point, b, c) != lineCheck(a, b, c) ||
      lineCheck(point, b, c) == 0)
    return false;
  return (true);
}