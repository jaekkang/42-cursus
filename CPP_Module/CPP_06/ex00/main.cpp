#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
    ScalarConverter obj;

    if (ac != 2)
        return (0);
    try {
        obj.convert(static_cast<std::string>(av[1]));
    } catch (const ScalarConverter::InvalidInput &e) {
        e.what();
    }

    return (0);
}