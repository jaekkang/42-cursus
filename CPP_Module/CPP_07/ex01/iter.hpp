#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void print(T &input) { std::cout << input; }

template <typename T>
void iter(T *arrAddress, size_t arrSize, void (*print)(T &)) {
    for (size_t i = 0; i < arrSize; i++) {
        print(arrAddress[i]);
    }
    std::cout << std::endl;
}

#endif