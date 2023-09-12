#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>

typename T::iterator easyfind(T a, int b) {
    typename T::iterator it;

    it = std::find(a.begin(), a.end(), b);
    if (it != a.end()) {
        return it;
    } else
        throw std::exception();
}

#endif