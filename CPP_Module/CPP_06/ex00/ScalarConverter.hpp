#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>

class ScalarConverter {
  private:
    static std::string input;

  public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter &operator=(const ScalarConverter &obj);

    void convert(std::string input) const;

    std::string getInput() const;

    class InvalidInput : public std::exception {
      public:
        const char *what(void) const throw();
    };
};

#endif