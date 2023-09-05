#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>

int easyfind(T a, int b) {
    typename T::iterator it;

    it = std::find(a.begin(), a.end(), b);
    if (it != a.end()) {
        std::cout << *it << std::endl;
        return *it;
    } else
        throw std::exception();
}

#endif