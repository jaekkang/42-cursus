#include "easyfind.hpp"

int main(void) {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        easyfind(v, 1);

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(v, 42);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(v, 20);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
