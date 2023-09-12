#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
  private:
    int _fixed;
    static const int _literal = 8;

  public:
    Fixed();
    Fixed(const Fixed &p);
    Fixed &operator=(const Fixed &p);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(const int raw);
};

#endif