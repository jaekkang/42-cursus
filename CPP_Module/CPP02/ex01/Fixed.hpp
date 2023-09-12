#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
  private:
    int _fixed;
    static const int _literal = 8;

  public:
    Fixed(void);
    Fixed(const Fixed &p);
    Fixed(const int number);
    Fixed(const float fnumber);
    Fixed &operator=(const Fixed &p);
    ~Fixed(void);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &p);

#endif