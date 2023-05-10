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
    explicit Fixed(const int number);
    explicit Fixed(const float fnumber);
    Fixed &operator=(const Fixed &p);
    ~Fixed(void);

    float toFloat(void) const;
    int toInt(void) const;

    const int getRawBits(void) const;
    void setRawBits(int const raw);

    static const Fixed &min(Fixed &p1, Fixed &p2);
    static const Fixed &min(const Fixed &p1, const Fixed &p2);
    static const Fixed &max(Fixed &p1, Fixed &p2);
    static const Fixed &max(const Fixed &p1, const Fixed &p2);

    Fixed operator*(const Fixed &p) const;
    Fixed operator/(const Fixed &p) const;
    Fixed operator+(const Fixed &p) const;
    Fixed operator-(const Fixed &p) const;
    bool operator<(const Fixed &p) const;
    bool operator>(const Fixed &p) const;
    bool operator>=(const Fixed &p) const;
    bool operator<=(const Fixed &p) const;
    bool operator==(const Fixed &p) const;
    bool operator!=(const Fixed &p) const;
    Fixed operator++(void);
    Fixed operator++(int);
    Fixed operator--(void);
    Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &os, const Fixed &p);

#endif