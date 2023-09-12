#include "easyfind.hpp"

int main(void) {
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    v.push_back(1);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    l.push_back(1);
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    d.push_back(1);
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

    if (!v.empty()) {
        std::cout << "v: " << v.front() << std::endl;
        std::cout << "v: " << v.back() << std::endl;
    }
    if (!l.empty()) {
        std::cout << "l: " << l.front() << std::endl;
        std::cout << "l: " << l.back() << std::endl;
    }

    if (!d.empty()) {
        std::cout << "d: " << d.front() << std::endl;
        std::cout << "d: " << d.back() << std::endl;
    }

    try {
        std::cout << "find : " << *easyfind(v, 1) << std::endl;
        std::cout << "find : " << *easyfind(l, 1) << std::endl;
        std::cout << "find : " << *easyfind(d, 1) << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "find : " << *easyfind(v, 42) << std::endl;
        std::cout << "find : " << *easyfind(l, 42) << std::endl;
        std::cout << "find : " << *easyfind(d, 42) << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "find : " << *easyfind(v, 20) << std::endl;
        std::cout << "find : " << *easyfind(l, 20) << std::endl;
        std::cout << "find : " << *easyfind(d, 20) << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
