#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe [expression]" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;

    pmergeMe.run(av);

    return 0;
}
