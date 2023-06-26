#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
  Point a(Fixed(1), Fixed(1));
  Point b(Fixed(1), Fixed(5));
  Point c(Fixed(5), Fixed(1));

  Point p(Fixed(1), Fixed(1));

  std::cout << std::boolalpha << bsp(a, b, c, p) << std::endl;
  return 0;
}