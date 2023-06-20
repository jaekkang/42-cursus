#include "iter.hpp"

int main(void) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    char b[3] = {'a', 'b', 'c'};

    std::string c[4] = {"Hello,", " ", " ", "World!"};

    iter(a, 10, print<int>);
    iter(b, 3, print<char>);
    iter(c, 4, print<std::string>);
    return (0);
}