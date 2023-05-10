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
    explicit Fixed(const int number); // 명시적으로 형변환이 작성되어야 사용가능
    explicit Fixed(const float fnumber);
    Fixed &operator=(const Fixed &p);
    ~Fixed(void);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &p);

#endif